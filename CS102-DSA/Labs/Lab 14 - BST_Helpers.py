#Binary Search Tree Helper Functions

# tree = {}

def insert(bst, key):
    if len(bst) == 0: #for null values, a new dictionary with the key is created at the leaf node
        bst['value'] = key
        bst['left'] = {}
        bst['right'] = {}
    elif key > bst['value']: #if key is greater than node, then the value is shifted to the right of node
        insert(bst['right'], key)
    elif key < bst['value']: #if key is lesser than node, then the value is shifted to the left of node
        insert(bst['left'], key)
    return bst

# lst = [8, 3, 10, 1, 6, 14, 4, 7, 13]

# for x in lst:
#     insert(tree, x)
# print(tree)

#--------------------------------------------------------------------------------------------------------------#

def exist(bst, key):
    if key == bst['value']:
        return True
    elif key > bst['value'] and bst['right'] != {}:
        return exist(bst['right'], key)
    elif key < bst['value'] and bst['left'] != {}:
        return exist(bst['left'], key)
    return False

# checks = [8, 3, 1, 5, 11, 13]
# for x in checks:
#     val = exist(tree, x)
#     if val == True:
#         print(f"{x} exists in the tree")
#     else:
#         print(f"{x} does not exist in the tree")

#--------------------------------------------------------------------------------------------------------------#

def minimum(bst, starting_node):
    if starting_node == bst['value'] and bst['left'] != {}:
        return minimum(bst['left'], bst['left']['value'])
    elif starting_node < bst['value'] and bst['left'] != {}:
        return minimum(bst['left'], starting_node)
    elif starting_node > bst['value'] and bst['right'] != {}:
        return minimum(bst['right'], starting_node)
    return bst['value']

# print(f"The minimum value is {minimum(tree, 8)}")

#--------------------------------------------------------------------------------------------------------------#

def maximum(bst, starting_node):
    if starting_node == bst['value'] and bst['right'] != {}:
        return maximum(bst['right'], bst['right']['value'])
    elif starting_node < bst['value'] and bst['left'] != {}:
        return maximum(bst['left'], starting_node)
    elif starting_node > bst['value'] and bst['right'] != {}:
        return maximum(bst['right'], starting_node)
    return bst['value']

# print(f"The maximum value is {maximum(tree, 8)}")

#--------------------------------------------------------------------------------------------------------------#

def inorder_traversal(bst, visited = []):
    if bst == {}:
        return visited
    if bst['left'] != {}:
        visited = inorder_traversal(bst['left'], visited)
    visited.append(bst['value'])
    if bst['right'] != {}:
        visited = inorder_traversal(bst['right'], visited)
    return visited

# print(f"In order traversal for the binary tree is {inorder_traversal(tree, [])}")

#--------------------------------------------------------------------------------------------------------------#

def preorder_traversal(bst, visited = []):
    if bst == {}:
        return visited
    visited.append(bst['value'])
    if bst['left'] != {}:
        visited = preorder_traversal(bst['left'], visited)
    if bst['right'] != {}:
        visited = preorder_traversal(bst['right'], visited)
    return visited

# print(f"Pre order traversal for the tree is {preorder_traversal(tree, [])}")

#--------------------------------------------------------------------------------------------------------------#

def postorder_traversal(bst, visited = []):
    if bst == {}:
        return visited
    if bst['left'] != {}:
        visited = postorder_traversal(bst['left'], visited)
    if bst['right'] != {}:
        visited = postorder_traversal(bst['right'], visited)
    visited.append(bst['value'])
    return visited

# print(f"Post order traversal for the tree is {postorder_traversal(tree, [])}")

#--------------------------------------------------------------------------------------------------------------#

#Q1
bst = {}
#(a)

vals = [68, 88, 61, 89, 94, 50, 4, 76, 66, 82]
for val in vals:
    bst = insert(bst, val)
print("Q1:\n")
print(bst)

#(b)
print(exist(bst, 50))

#(c)
print(exist(bst, 49))

#(d)
print(f"The minimum value starting from node 68 is {minimum(bst, 68)}")

#(e)
print(f"The minimum value starting from node 88 is {maximum(bst, 88)}")

#(f)
print(f"The maximum value starting from node 68 is {maximum(bst, 68)}")

#(g)
print(f"The maximum value starting from node 61 is {maximum(bst, 61)}")

#(h)
print(f"In order traversal of the bst is {inorder_traversal(bst, [])}")

#(i)
print(f"Pre order traversal of the bst is {preorder_traversal(bst, [])}")

#(j)
print(f"Post order traversal of the bst is {postorder_traversal(bst, [])}")

#--------------------------------------------------------------------------------------------------------------#

#Q2
bst_words = {}
words = ['begin', 'do', 'else', 'end', 'if', 'then', 'while']
for word in words:
    bst_words = insert(bst_words, word)
print("\n\nQ2\n")
print(bst_words)
