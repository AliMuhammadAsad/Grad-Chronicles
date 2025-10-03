import array as arr

'''Implementation of DynamicArrayList was seen, influenced and inspired from the following sources:
https://www.geeksforgeeks.org/implementation-of-dynamic-array-in-python/
https://www.tutorialspoint.com/implementation-of-dynamic-array-in-python
The above links were comprehensive, and were a huge help to understand the implementation of DynamicArrayList'''

class DynamicArrayList:
    def __init__(self):
        self.count = 0 #Keeps track of number of elements
        self.cap = 1 #capacity
        self.array = arr.array("i", [-1] * self.cap) #Initialising an empty array of size 2 and -1 element values

    def resize(self, new_cap):
        temp = arr.array("i", [-1] * new_cap) #A temporary array created with the new size
        for i in range(self.count): #looping over the count of elements in the list
            temp[i] = self.array[i] #the elements from previous array are shifted to the new array with greater size
        self.array = temp; self.cap = new_cap #the old array is now made the new array and the old capacity updated
    
    def insert(self, index:int, value):
        if index < 0 or index > self.count: #If index is not within the range, then an Exception is thrown
            raise Exception("Index out of range")
        if self.count == self.cap: #If the elements in the array reaches the maximum size, resize is called with 2n size where n is the old capacity of the array
            self.resize(self.cap * 2)
        for i in range(self.count, index, -1): #Traversing back over the elements, each element is shifted one place to the right to accomodate for the new element to be inserted
            self.array[i] = self.array[i - 1]
        self.array[index] = value #value at the index updated => element added
        self.count += 1 #count of elements is increased
    
    def delete(self, index):
        if index < 0 or index > self.count: raise Exception("Index does not exist within the list") #If index is not within range, then an Exception is thrown 
        self.count -= 1 #Index is within range, therefore count of elements is decreased as an element is to be deleted
        for i in range(index, self.count): #starting from the index which we want to delete till the last element in the array, the elements are shifted one space to the left, hence deleting the element
            self.array[i] = self.array[i + 1]
        for i in range(self.count, self.cap): #fills the extra element(s) with -1
            self.array[i] = -1
        if self.count <= self.cap // 4: #If resize condition is met, that is number of elements are quarter of the size of the array, the array size is halved and the new size updated
            self.resize(self.cap // 2)

    def display(self):
        return(list(self.array))

    def get(self, index:int):
        if index > self.count: raise Exception("Index out of range")
        else: return self.array[index]
    
    def size(self):
        return self.count


'''Similarly, idea, inspiration, and understanding of the implementation for the linked list was taken from the following links:
https://www.tutorialspoint.com/python_data_structure/python_linked_lists.htm
https://www.geeksforgeeks.org/what-is-linked-list/
https://www.geeksforgeeks.org/header-linked-list-in-c/
https://www.educative.io/answers/how-to-create-a-linked-list-in-python'''

class Node:
    def __init__(self, data)->None:
        self.data = data #Initialising the node with data and pointing Next to None
        self.next = None 

class LinkedList:
    def __init__(self):
        self.front = None #Front of the list / starting point of the list

    def insert(self, index, value):
        newnode = Node(value) #NewNode created
        if self.front is None: self.front = newnode; return #If LinkedList has no elements, then the front of the list is made the newnode
        if index == 0: #If the node is to be inserted at the front, then the newnode can be made to point to the front of the list first, and then the front can be changed to be made the newnode
            newnode.next = self.front
            self.front = newnode
            return
        current = self.front #We start from the front of the list
        for i in range(index - 1): #We traverse from front till the previous index from the required index
            current = current.next
            if current is None:
                break
        newnode.next = current.next #The newnode is made to point to the node currently at the required index
        current.next = newnode #The previous node was made to point to the newnode, hence inserting the newnode at the required index
    
    def delete(self, index):
        if self.front is None: #If LinkedList is empty, an Exception to be raised that the list has no elements to delete
            raise Exception("Linked List is empty, so no elements can be deleted") 
        if index == 0: #If the first element has to be deleted, then the front can simply be updated to the next value, hence breaking the link and deleting the element
            self.front = self.front.next
            return
        current = self.front #We start from the front of the list
        for i in range(index - 1): #We traverse from front till the previous inde from the required index
            current = current.next
            if current is None: break
        if current is None or current.next is None: #If the current element is None or there is no other element after it, then the index doesn't exist so exception thrown
            raise Exception("Item can't be deleted as index does not exist")
        current.next = current.next.next #The previous node from the index is made to point to the next's next node, hence skipping over the index which breaks the link and deletes the element.

    def display(self): 
        lst = []; current = self.front #Initialising an empty list to store the values and starting from the front of the list
        while current: #While current exists, append elements to the list and point current to the next element
            lst.append(current.data); current = current.next
        return lst
    
    def size(self):
        size = 0; current = self.front #Initialize size to 0, and start from the front of the list
        while current: #While current exists, size is incremented and point current to the next element
            size += 1; current = current.next
        return size
    
    def get(self, index):
        current = self.front #Starting from the front of the list
        for i in range(index): #We traverse over the count of elements or until we reach an empty node
            current = current.next
            if current is None:
                break
        return current.data if current else None #Return the element or return None

def load(file_path, out_file):
    """
    Loads and performs the operations specified in the input file on either a dynamic array list or a linked list.

    :param file_path: the path of the input file
    :type file_path: str
    :param out_file: the name of the output file
    :type out_file: str
    """
    with open(file_path, 'r') as file:
        data_structure = file.readline().strip()
        operations = file.readlines()
        out = []
        if data_structure == "array":
            ds = DynamicArrayList()
        else:
            ds = LinkedList()
        for op in operations:
            op = op.strip().split()
            if op[0] == "delete":
                ds.delete(int(op[1]))
            elif op[0] == "get":
                out.append(ds.get(int(op[1])))
            elif op[0] == "size":
                out.append(ds.size())
            elif op[0] == "display":
                out.append(ds.display())
            elif op[0] == "insert":
                ds.insert(int(op[1]), int(op[2]))
            
        with open(out_file, 'w') as f:
            for item in out:
                f.write("%s\n" % item)
