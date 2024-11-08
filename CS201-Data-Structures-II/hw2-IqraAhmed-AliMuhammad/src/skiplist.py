import random
import sys
from typing import Any, Optional

'''Implementation of SkipList was understood from various sources;
https://gist.github.com/gmohandas/aece64683ce48fb14714e5f36b84f68a
https://gist.github.com/sachinnair90/3bee2ef7dd3ff0dc5aec44ec40e2d127
https://www.geeksforgeeks.org/skip-list/?ref=rp
https://www.geeksforgeeks.org/skip-list-set-2-insertion/
https://www.geeksforgeeks.org/skip-list-set-3-searching-deletion/?ref=rp
Open Data Structures by Pat Morin
'''

class Node(object):
    '''A node in a skiplist. It stores a (key, value) pair along with pointers
    for each level in its tower.

    The key is used to compare nodes. The tower automatically includes level 0.
    '''
    
    def __init__(self, data: (Any,Any), height: int=0) -> None:
        '''Construct node with given data and of given height.

        The height is the largest level, starting from 0, of the tower.

        Parameters:
        - self: mandatory reference to this object
        - data: the (key, value) pair to store in this node
        - height: the number of levels in the tower (excludes level 0)

        Returns:
        None
        '''
        self.kee, self.val = data[0], data[1]
        self.next = [None] * (height + 1)
        

    def __repr__(self) -> str:
        '''Returns the representation of this node.

        Implement any representation that helps you debug.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        this node's string representation.
        '''
        #Representation must have key value pair, and the list of next nodes to be displayed
        return f"Node:{(self.kee, self.val)}, {self.next}"

    ''' Understanding difference between str() and repr() 
    str() is used for creating output for end user while repr() is mainly used for debugging and dev. repr's goal is to be unambigous and str's to be readable
        - repr() => representation has all the information about the object, meaining we can reconstruct the object
        - str() => representation is useful for printing the object
    repr() is for developers, str() is for customers
    if you override repr(), its also used for str() but not vice versa '''

    def __str__(self) -> str:
        '''Returns a string representation of this node.

        See the link below for the difference between the __repr__ and __str__
        methods: https://www.geeksforgeeks.org/str-vs-repr-in-python/

        Parameters:
        - self: mandatory reference to this object

        Returns:
        this node's string representation.
        '''
        return self.__repr__()
    
    def height(self) -> int:
        '''Returns the height of this node's tower.

        The height is the largest level, starting from 0, of the tower.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        the height of this node's tower.
        '''
        return len(self.next)

    def key(self) -> Any:
        '''Returns the key stored in this node.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        the key stored in this node.
        '''
        return self.kee

    def value(self) -> Any:
        '''Returns the value stored in this node.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        the value stored in this node.
        '''
        return self.val

    def add_level(self, forward: Optional[Any] = None) -> None:
        '''Adds a level to this node which points to forward.

        Parameters:
        - self: mandatory reference to this object
        - forward: the node that this node will point to in the new level.

        Returns:
        None.
        '''
        self.next.append(forward)
    
    def set_val(self, value: Any)->None:
        '''Setter function for setting/updating the value of any given Node
        
        Parameters:
        - self: mandatory reference to this object
        - value: new value that will replace the old value

        Returns:
        None
        '''
        self.val = value


class SkipList(object):
    '''A skiplist of nodes containing (key, value) pairs. Nodes are ordered
    according to keys. Keys are unique, reinserting an existing key overwrites
    the value.

    The skiplist contains a sentinel node by default and the height of the
    sentinel node is the height of the list.
    '''

    def __init__(self) -> None:
        '''Construct empty skiplist.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        None
        '''
        self.maxlevels = 20 #max levels for the skiplist - can be any sufficient value
        self.elements = 0 #number of elements in the skiplist
        self.curr_height = 0 #current level/height of the skiplist
        self.sentinel = Node((None, None), self.maxlevels) #initialising the head of the skiplist - sentinal node
        
    def __len__(self) -> int:
        '''Returns the number of pairs stored in this skiplist.

        dunder method allows calling len() on this object.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        the number of pairs stored in this skiplist.
        '''
        return self.elements #Number of elements corresponds to the length of the skiplist

    def __repr__(self) -> str:
        '''Returns a string representation of this skiplist.

        Implement any representation that helps you debug.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        this skiplist's string representation.
        '''
        #A representation of the skiplist that shows different nodes at different levels along with the node the point to and their heights - string representation
        levels = []
        for i in range(self.maxlevels):
            level = f"Level {i}:"
            node = self.sentinel.next[i]
            while node is not None:
                level += str(node) + "->"
                node  = node.next[i]
            levels.append(level)
        return "\n".join(levels)
    
    def __str__(self) -> str:
        '''Returns a string representation of this skiplist.

        See the link below for the difference between the __repr__ and __str__
        methods: https://www.geeksforgeeks.org/str-vs-repr-in-python/

        Parameters:
        - self: mandatory reference to this object

        Returns:
        this skiplist's string representation.
        '''
        return self.__repr__()

    def _search_path(self, key: Any) -> [Node]:
        '''Returns the search path in this skiplist for key.

        The search path contains one node for each level of the skiplist
        starting from the highest and ending at level 0. The node for each
        level is the one corresponding to a descend in the search path.

        Parameters:
        - self: mandatory reference to this object
        - key: the key being searched for

        Returns:
        the descend nodes at each level of the skiplist, ordered from highest
        level to level 0.
        '''
        path = [None] * (self.maxlevels) #Initializing an empty path with at most maximum level length as that is required to traverse through the whole skiplist
        node = self.sentinel #We start from the sentinel node
        for level in range(self.maxlevels - 1, -1, -1): #From the higher node, we drop down hence reversed order
            while node.next[level] and node.next[level].key() < key: #If node exists and key is still less than the required key, we move onto the next one
                node = node.next[level] 
            path[level] = node #When required key is found or next node is none, the current node is added to path - hence path stored
        return path

    def _find_prev(self, key: Any) -> Node:
        '''Returns the node in the skiplist that contains the predecessor key.

        Parameters:
        - self: mandatory reference to this object
        - key: the key being searched for

        Returns:
        the node in the skiplist that contains the predecessor key.
        '''
        path = self._search_path(key) #First we find the search path for the required key
        return path[0] if len(path) > 1 else None #Having path greater than 1 means the path exist, hence we return the node at level 0 of path, else there is no element so None returned

    def reset(self) -> None:
        '''Empty the skiplist.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        None
        '''
        self.sentinel = Node((None, None), self.maxlevels) #Reset the sentinel
        self.elements = 0; self.curr_height = 0 #elements reset to 0 and current height also reset to 0

    def height(self) -> int:
        '''Returns the height of the skiplist.

        The height is the largest level of the sentinel's tower.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        the height of this skiplist.
        '''
        return self.curr_height #Keeping track of current height

    def find(self, key: Any) -> Optional[Any]:
        '''Returns the value stored in this skiplist corresponding to key, None
        if key does not exist in this skiplist.

        Parameters:
        - self: mandatory reference to this object
        - key: the key whose value is sought

        Returns:
        the stored value for key, None if key does not exist in this skiplist.
        '''
        predec = self._find_prev(key) #using search path and find_prev, the node at level 0 is found
        if predec.next[0] and predec.next[0].key() == key: #if node exists the key is as required, the value is returned, else None
            return predec.next[0].value()
        return None

    def find_range(self, key1: Any, key2: Any) -> [Any]:
        '''Returns the values stored in this skiplist corresponding to the keys
        between key1 and key2 inclusive in sorted order of keys.

        Parameters:
        - self: mandatory reference to this object
        - key1: starting key in the range of keys whose value is sought
        - key2: ending key in the range of keys whose value is sought

        Returns:
        the stored values for the keys between key1 and key2 inclusive in sorted
        order of keys.
        '''
        predec = self._find_prev(key1); vals = [] #Node at level 0 of key1 and empty values list initialised to store range of values
        while predec.next[0] and predec.next[0].key() <= key2: #While the next node exists and its key is less than key2, it is added to the values list and predec is updated to the next node
            vals.append(predec.next[0].value())
            predec = predec.next[0]
        return vals


    def remove(self, key: Any) -> Optional[Any]:
        '''Returns the value stored for key in this skiplist and removes
        (key, value) from this skiplist, returns None if key is not stored in
        this skiplist.

        Parameters:
        - self: mandatory reference to this object
        - key: the key to be removed

        Returns:
        the stored value for key in this skiplist, None if key does not exist
        in this skiplist
        '''
        path = self._search_path(key) #The path is first found using the search path
        if len(path) <= 1: return None
        node = path[0].next[0] #Starting from the first node - sentinel
        if node and node.key() == key: #If node exists and key is equal to the key we want to delete
            for level in range(len(node.next)): #Traverse over all the levels 
                if path[level].next[level] and path[level].next[level].key() == key: #If at that specific level the path value exists, and is equal to the key we want to delete, then we assign its next value to the value after the key we want to delete
                    path[level].next[level] = path[level].next[level].next[level]
            self.elements -= 1 #Total elements reduced by 1
        return node.value()

    def insert(self, data: (Any,Any)) -> None:
        '''Inserts a (key value) pair in this skiplist, overwrites the old value
        if key already exists.

        Parameters:
        - self: mandatory reference to this object
        - data: the (key, value) pair

        Returns:
        None
        '''
        kee, val = data[0], data[1] #Key and value are seperated from the data
        level = self.curr_height; start = self.sentinel #start is initilaised to the sentinel, and level is initialised to the height of the skiplist
        lst = [None] * (self.curr_height + 1) #list to keep track of all nodes at each level of path
        while level >= 0: #from height of the skiplist till the base of the skiplist
            while start.next[level] and start.next[level].key() < kee: #while a node exists and its key is less than the key we want to insert at, we move to the next 
                start = start.next[level] 
            if start.next[level] and start.next[level].key() == kee: #if the node exists at the level and its key is equal to the key we want to insert at, then the value of the node at that level is updated to the new value
                start.next[level].set_val(val); return 
            lst[level] = start 
            level -= 1 #one level decremented 
        self.elements += 1 #number of elements updated in the skiplist for new node
        h = self.height_randomizer() #get random height for the new node to insert new node
        newnode = Node(data, h) #New node initialised
        for i in range(self.curr_height, h): #if and while the height of the newnode is greater than the height of the skiplist, height of the skiplist is updated and sentinel is kept track of in the list of path
            self.curr_height += 1; lst.append(self.sentinel)
        for i in range(h + 1): #From level 0 till height of the new node we point the node at each level to the next possible node at that level and update the list accordingly
            newnode.next[i] = lst[i].next[i]
            lst[i].next[i] = newnode

    def size(self) -> int:
        '''Returns the number of pairs stored in this skiplist.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        the number of pairs stored in this skiplist.
        '''
        return self.elements #size is kept track of by number of elements
    
    def is_empty(self) -> bool:
        '''Returns whether the skiplist is empty.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        True if no pairs are stored in this skiplist, False otherwise.
        '''
        return True if self.elements == 0 else False
    
    def height_randomizer(self): #Height randomizer function to randomly generate height for the new nodes while inserting
        h = 0
        while random.random() < 0.5 and h < self.maxlevels: h += 1
        return h

