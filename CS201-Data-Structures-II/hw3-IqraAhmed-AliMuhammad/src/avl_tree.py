from typing import List, Tuple # Here the List and Tuple classes are imported from the typing module to be used later in the code to define data type of variables

class AVLTreeNode: # This class represents a single node in the AVL tree 
    def __init__(self, key: str, value: Tuple[int, int]): # This is the constructor method that will be called whenever a new instance of AVLTreeNode is created. It takes two parameters: key (string) and value (a tuple of two integers) which are then used to initialize the instance variables key, value, left, right, and height.
        self.key = key # The key attribute of the node is initialized with key passed to constructor.
        self.value = value  # The value attribute of the node is initialized with value passed to constructor.
        self.left = None # The left attribute of the node is initialized with value None. This attribute references the left child of the node.
        self.right = None # The right attribute of the node is initialized with value None. This attribute references the right child of the node. 
        self.height = 1 # This height attribute of the node is initialized with value 1. This attribute will keep track of the height of the node in the AVL tree. 

class AVLTree: # This class represents the AVLTree object
    def __init__(self): # This constructor method is called whenever a new instance of AVLTree is created. It takes only one argument, self 
        self.root = None # This line initializes root attribute of AVLTree to None. This will be used to keep track of the root node of the tree. When the tree is empty, self.root will be None.

    def insert(self, key: str, value: Tuple[int, int]) -> None: # This method is responsible for inserting a new node with the given key(str) and value (a tuple of two integers) into the AVL tree. It calls the _insert method with the root node of the AVL tree and the given key and value.
        self.root = self._insert(self.root, key, value) #

    def search(self, key: str) -> List[Tuple[int, int]]: # This method takes a key (string) and returns a list of integer tuples. Purpose of method is to search for a node in the AVL tree that matches the given key.
        node = self.root # This variable references the current node. The search starts from the root node so this is initialized as root of tree
        while node: # used to iterate over nodes in tree, will exit once a nill node is reached 
            if node.key == key: # if key value matches current node, return Value of node
                return node.value
            elif node.key < key: # if current nodde less than key value continue search on right child of node 
                node = node.right
            else: # if current node greater than key value continue search on left child of node
                node = node.left
        return [] # key value not found so return empty list

    def rotate_left(self, node: AVLTreeNode) -> None: # This function takes an AVLTreeNode object as input and performs left rotation on subtree rooted at that node. This helper function helps maintain the balance of the AVL tree.
        right = node.right # a new node right is created that refers to the right child of the given node. 
        node.right = right.left # right child of node is set to left child of right
        right.left = node # left child of right is set to node
        node.height = max(self._height(node.left), self._height(node.right)) + 1 # height of node is updated with help of heights of children of node
        right.height = max(self._height(right.left), self._height(right.right)) + 1 # height of right child is updated with help of heights of its children
        return right

    def rotate_right(self, node: AVLTreeNode) -> None: # This function takes an AVLTreeNode object as input and performs right rotation on subtree rooted at that node. This helper function helps maintain the balance of the AVL tree.
        left = node.left # a new node left is created that refers to the left child of the given node.
        node.left = left.right # left child of node is set to right child of left
        left.right = node # right child of left is set to node
        node.height = max(self._height(node.left), self._height(node.right)) + 1 # height of node is updated with help of heights of children of node; adding one to max out of the two
        left.height = max(self._height(left.left), self._height(left.right)) + 1 # height of left child is updated with help of heights of its children; adding one to max out of the two
        return left #

    def display(self) -> List[str]: # This function returns a list of strings that represents the inorder traversal of the AVL tree.
        result = [] # an empty list result is created
        self._in_order(self.root, result) #_in_order function is called with the root node and the result list as parameters
        return result # the result list containing the inorder traversal of the AVL tree is returned

    def _insert(self, node: AVLTreeNode, key: str, value: Tuple[int, int]) -> AVLTreeNode: # This method recursively inserts a new node with the given key and value into the AVL tree. 
        if not node: # If the current node is None
            return AVLTreeNode(key, value) # a new node with the given key and value is created and returned
        elif node.key == key: # If the current node already has the same key as the new node
            node.value.append(value) # value of the existing node is updated with the new value
            return node # existing node is returned
        elif node.key < key: # If the key of the new node is greater than the key of the current node 
            node.right = self._insert(node.right, key, value) # the new node is inserted into the right subtree
        else: # If the key of the new node is less than the key of the current node
            node.left = self._insert(node.left, key, value) # the new node is inserted into the left subtree.
        node.height = max(self._height(node.left), self._height(node.right)) + 1 #After inserting new node, height of current node is updated based on heights of left and right subtrees; adding one to max out of the two
        balance = self._balance_factor(node) # The balance factor of the current node is calculated based on the difference between the heights of its left and right subtrees.
        if balance > 1 and key < node.left.key: # If the balance factor of the current node is greater than 1 and the key of the new node is less than the key of the current node's left child, a right rotation is performed to balance the tree.
            return self.rotate_right(node) 
        if balance < -1 and key > node.right.key: # If the balance factor of the current node is less than -1 and the key of the new node is greater than the key of the current node's right child, a left rotation is performed.
            return self.rotate_left(node) 
        if balance > 1 and key > node.left.key: # If the balance factor is greater than 1 and the key of the new node is greater than the key of the current node's left child, a left rotation is performed on the left child followed by a right rotation on the current node to balance the tree.
            node.left = self.rotate_left(node.left) 
            return self.rotate_right(node) 
        if balance < -1 and key < node.right.key: # If the balance factor is less than -1 and the key of the new node is less than the key of the current node's right child, a right rotation is performed on the right child followed by a left rotation on the current node to balance the tree.
            node.right = self.rotate_right(node.right) 
            return self.rotate_left(node) 
        return node # Current node is returned

    def _height(self, node: AVLTreeNode) -> int: # This method returns the height of the given AVLTreeNode instance. If the node is None, i.e., it doesn't exist, the method returns 0.
        return node.height if node else 0 

    def _balance_factor(self, node: AVLTreeNode) -> int: # This method calculates the balance factor of the given AVLTreeNode instance. 
        return self._height(node.left) - self._height(node.right) # Balance factor is calculated as difference between height of left subtree and  height of right subtree.

    def _in_order(self, node: AVLTreeNode, result: List[str]) -> None: # This method performs an in-order traversal of the AVLTree. It takes two arguments: the current node being traversed and a list to which the keys of the nodes are appended in sorted order.
        if node: # If the current node is not None
            self._in_order(node.left, result) # Recursive call on the left subtree
            result.append(node.key) # Appends key of current node to the result list
            self._in_order(node.right, result) # Recursive call on the right subtree

## The below implementations were my implementations to the AVL Tree ##

# from typing import Any

# class AVLTreeNode: #Node Class for the AVL Tree
#     def __init__(self, key: str, value: Any) -> None: #Initializing the values
#         self.key = key #key
#         self.value = value #value
#         self.left = None; self.right = None #left and right nodes
#         self.height = 1 #height

# class AVLTree: #AVL Tree Class
#     def __init__(self) -> None:
#         self.root = None #initializing root to None
    
#     def insert(self, key: str, value: Any) -> None: #Insert function
#         self.root = self._insert_(self.root, key, value) #inserting the node to the root with the help of a helper function
    
#     def _insert_(self, node: AVLTreeNode, key: str, value: Any) -> AVLTreeNode: #Helper function to insert the nodes
#         if node == None: #If the node is None, create a new node and return the new node with the key and value
#             return AVLTreeNode(key, value)
#         if key < node.key: #if key is less than the node's key
#             node.left = self._insert_(node.left, key, value) #then we move towards the left child and check over there recursively
#         elif key > node.key: #if key is greater than the node's key
#             node.right = self._insert_(node.right, key, value) #then we move towards the right child and check over there recursively
#         elif key == node.key: #if the key is equal to the required key
#             return node #return the node
#         node.height = 1 + max(self._getheight_(node.left), self._getheight_(node.right)) #Update the height of the node - new height will be the greater one of either the left or the right sub tree hence we take max of both the trees -> again max is taken with a helper function _getheight_ that is used to compute the height of the tree
#         balance_check = self._balancecheck_(node) #A variable to check whether the AVL Tree property is violated or not, and balance the tree accordingly in either of the 4 cases
#         if balance_check > 1 and key < node.left.key: #if violation is at left child, we perform the right rotation 
#             return self.rotate_right(node) 
#         if balance_check > 1 and key > node.left.key: #if violation is at left but we have to perform left right rotation -> double rotation 
#             node.left = self.rotate_left(node.left) #we first perform left rotation on the left child
#             return self.rotate_right(node) #then we perform right rotation on the node
#         if balance_check < -1 and key > node.right.key: #if violation is at right child, we perform the left rotation 
#             return self.rotate_left(node)
#         if balance_check < -1 and key < node.right.key: #if violation is at right but we have to perform right left rotation -> double rotation
#             node.right = self.rotate_right(node.right) #we first perform right rotation on the right child
#             return self.rotate_left(node) #then left rotation on the node
#         return node #return the node

#     def search(self, key: str) -> Any: #search for a given key in the AVL Tree
#         node = self._search_(self.root, key) #a helper function to accomodate us in the search function
#         if node: return node.value #if node exists, then we return its value
#         else: return [] #else we return an empty list
    
#     def _search_(self, node: AVLTreeNode, key: str) -> AVLTreeNode: #helper function for the search function
#         if node == None: return None #if node is None, return Noen
#         elif key == node.key : #if key is equal to the node's key, return the node
#             return node
#         elif key < node.key: #if key is less than the node's key, we search in the left subtree recursively 
#             return self._search_(node.left, key)
#         elif key > node.key: #if key greater than the node's key, we search in the right subtree recursively
#             return self._search_(node.right, key)

#     def _getheight_(self, node: AVLTreeNode) -> int: #get height helper function to return the height of the node
#         if node == None: return 0 #if there is no node, return 0
#         return node.height #else return the node's height which is stored through the node's class

#     def _balancecheck_(self, node:AVLTreeNode) -> int: #helper function to check whether the tree is balanced or not -> if not balanced then we have a violation and rotation must be performed
#         if node == None: return 0 #if there is no node, then return 0
#         return self._getheight_(node.left) - self._getheight_(node.right) #else use the getheight helper function to take the difference between the height of the left subtree and the height of the right subtree and use that to check for violation condition
    
#     def rotate_left(self, node: AVLTreeNode) -> AVLTreeNode: #rotate left function
#         new_root = node.right #we assign the right node to a new root node as that node would become the new parent/root after rotation
#         node.right = new_root.left #the new root's left subtree becomes the node's right subtree
#         new_root.left = node #The node becomes the new root's left subtree
#         node.height = 1 + max(self._getheight_(node.left), self._getheight_(node.right)) #re adjusting the height of the node
#         new_root.height = 1 + max(self._getheight_(new_root.left), self._getheight_(new_root.right)) #new root node's height is computed and set
#         return new_root #return the new root node

#     def rotate_right(self, node: AVLTreeNode) -> AVLTreeNode: #rotate right function
#         new_root = node.left #we assign the left node to a new root node as that node would become the new parent/root after rotation
#         node.left = new_root.right #the new root's right subtree becomes the node's left subtree
#         new_root.right = node #The node becomes the new root's right subtree
#         node.height = 1 + max(self._getheight_(node.left), self._getheight_(node.right)) #re adjusting the height of the node
#         new_root.height = 1 + max(self._getheight_(new_root.left), self._getheight_(new_root.right)) #setting the height of the new root
#         return new_root #returning the new root

#     def display(self) -> Any: #Display function
#         return self._inorder_traversal_(self.root) #We use another helper function to compute the in order traversal of the AVL Tree and use that to return the AVL Tree representation 

#     def _inorder_traversal_(self, node: AVLTreeNode) -> Any: #Helper in order traversal function
#             result = [] #empty list to store the key values
#             if node != None: #if node is not None
#                 self._inorder_traversal_(node.left) #traverse in the left subtree
#                 result.append(node.key) #append the key to the list
#                 self._inorder_traversal_(node.right) #traverse in the right subtree
#             return result

## The class below shows required outputs for the below custom tests, but not the test cases file. Will have to check and debug again to support both things

# class AVLTree: #AVL Tree Class
#     def __init__(self) -> None:
#         self.root = None #initializing root to None
    
#     def insert(self, key: str, value: Any) -> None: #Insert function
#         self.root = self._insert_(self.root, key, value) #inserting the node to the root with the help of a helper function
    
#     def _insert_(self, node: AVLTreeNode, key: str, value: Any) -> AVLTreeNode: #Helper function to insert the nodes
#         if node == None: #If the node is None, create a new node and return the new node with the key and value
#             return AVLTreeNode(key, value)
#         if key < node.key: #if key is less than the node's key
#             node.left = self._insert_(node.left, key, value) #then we move towards the left child and check over there recursively
#         elif key > node.key: #if key is greater than the node's key
#             node.right = self._insert_(node.right, key, value) #then we move towards the right child and check over there recursively
#         elif key == node.key: #if the key is equal to the required key
#             node.value.append(value) #append the value to the values of the key of the node
#             return node #return the node
#         node.height = 1 + max(self._getheight_(node.left), self._getheight_(node.right)) #Update the height of the node - new height will be the greater one of either the left or the right sub tree hence we take max of both the trees -> again max is taken with a helper function _getheight_ that is used to compute the height of the tree
#         balance_check = self._balancecheck_(node) #A variable to check whether the AVL Tree property is violated or not, and balance the tree accordingly in either of the 4 cases
#         if balance_check > 1 and key < node.left.key: #if violation is at left child, we perform the right rotation 
#             return self.rotate_right(node) 
#         if balance_check > 1 and key > node.left.key: #if violation is at left but we have to perform left right rotation -> double rotation 
#             node.left = self.rotate_left(node.left) #we first perform left rotation on the left child
#             return self.rotate_right(node) #then we perform right rotation on the node
#         if balance_check < -1 and key > node.right.key: #if violation is at right child, we perform the left rotation 
#             return self.rotate_left(node)
#         if balance_check < -1 and key < node.right.key: #if violation is at right but we have to perform right left rotation -> double rotation
#             node.right = self.rotate_right(node.right) #we first perform right rotation on the right child
#             return self.rotate_left(node) #then left rotation on the node
#         return node #return the node

#     def search(self, key: str) -> Any: #search for a given key in the AVL Tree
#         node = self._search_(self.root, key) #a helper function to accomodate us in the search function
#         if node: return node.value #if node exists, then we return its value
#         else: return [] #else we return an empty list
    
#     def _search_(self, node: AVLTreeNode, key: str) -> AVLTreeNode: #helper function for the search function
#         if node == None: return None #if node is None, return Noen
#         elif key == node.key : #if key is equal to the node's key, return the node
#             return node
#         elif key < node.key: #if key is less than the node's key, we search in the left subtree recursively 
#             return self._search_(node.left, key)
#         elif key > node.key: #if key greater than the node's key, we search in the right subtree recursively
#             return self._search_(node.right, key)

#     def _getheight_(self, node: AVLTreeNode) -> int: #get height helper function to return the height of the node
#         if node == None: return 0 #if there is no node, return 0
#         return node.height #else return the node's height which is stored through the node's class

#     def _balancecheck_(self, node:AVLTreeNode) -> int: #helper function to check whether the tree is balanced or not -> if not balanced then we have a violation and rotation must be performed
#         if node == None: return 0 #if there is no node, then return 0
#         return self._getheight_(node.left) - self._getheight_(node.right) #else use the getheight helper function to take the difference between the height of the left subtree and the height of the right subtree and use that to check for violation condition
    
#     def rotate_left(self, node: AVLTreeNode) -> AVLTreeNode: #rotate left function
#         new_root = node.right #we assign the right node to a new root node as that node would become the new parent/root after rotation
#         node.right = new_root.left #the new root's left subtree becomes the node's right subtree
#         new_root.left = node #The node becomes the new root's left subtree
#         node.height = 1 + max(self._getheight_(node.left), self._getheight_(node.right)) #re adjusting the height of the node
#         new_root.height = 1 + max(self._getheight_(new_root.left), self._getheight_(new_root.right)) #new root node's height is computed and set
#         return new_root #return the new root node

#     def rotate_right(self, node: AVLTreeNode) -> AVLTreeNode: #rotate right function
#         new_root = node.left #we assign the left node to a new root node as that node would become the new parent/root after rotation
#         node.left = new_root.right #the new root's right subtree becomes the node's left subtree
#         new_root.right = node #The node becomes the new root's right subtree
#         node.height = 1 + max(self._getheight_(node.left), self._getheight_(node.right)) #re adjusting the height of the node
#         new_root.height = 1 + max(self._getheight_(new_root.left), self._getheight_(new_root.right)) #setting the height of the new root
#         return new_root #returning the new root

#     def display(self) -> Any: #Display function
#         return self._inorder_traversal_(self.root) #We use another helper function to compute the in order traversal of the AVL Tree and use that to return the AVL Tree representation 

#     def _inorder_traversal_(self, node: AVLTreeNode) -> Any: #Helper in order traversal function
#             result = [] #empty list to store the key values
#             if node != None: #if node is not None
#                 result.extend(self._inorder_traversal_(node.left))
#                 result.append(str(node.key) + ": " + str(node.value))
#                 result.extend(self._inorder_traversal_(node.right))
#             return result

# A = AVLTree()
# # Left Rotation
# print("Inserting 8")
# A.insert(8,1)
# print("Inserting 9")
# A.insert(9,1)
# print("Inserting 10")
# A.insert(10,2)
# A.insert(10, 1)
# A.insert(10, 3)
# A.insert(9, 2)
# A.insert(8, 3)
# A.insert(7, 1)
# A.insert(7, 2)
# A.insert(12, 1)
# A.insert(12, 10)
# A.insert(13, 2)
# A.insert(13, 3)
# print(A.display())