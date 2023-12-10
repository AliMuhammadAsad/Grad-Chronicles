# Graph Helper Functions

#-------------------------------------------------------------------------------------------------#
#Add Nodes helper function

# G = {}
# nodes = [0, 1, 2, 3, 4, 5]
def addNodes(G, nodes):
    for i in nodes:
        G[i] = []
    # return G
# print(addNodes(G, nodes))
# print(G)

#-------------------------------------------------------------------------------------------------#
#Add edges helper function

# edge_list = [(0, 1, 1), (0, 2, 1), (1, 2, 1), (1, 3, 1), (2, 4, 1), (3, 4, 1), (3, 5, 1), (4, 5, 1)]
def addEdges(G, edges, directed):
    for key, value, weight in edges:
        G[key].append((value, weight))
        if directed == False:
            G[value].append((key, weight))
    # return G

# print(addEdges(G, edge_list, True))
# print(addEdges(G, edge_list, False))
# print(G)

#-------------------------------------------------------------------------------------------------#
#Return list of nodes in a graph

def listOfNodes(G):
    nodes = []
    for key in G:
        nodes.append(key)
    return nodes

# print(listOfNodes(G))

#-------------------------------------------------------------------------------------------------#
#Return List of edges of a graph

def listOfEdges(G, directed):
    edges = []
    check_lst = []
    for key in G:
        vals = G.get(key)
        for x in range(len(vals)):
            if directed == True:
                edges.append((key, vals[x][0], vals[x][1]))
            else:
                if (vals[x][0], key, vals[x][1]) in edges:
                    pass
                else:
                    edges.append((key, vals[x][0], vals[x][1]))
    return edges

# print(listOfEdges(G, False))
# print(listOfEdges(G, True))

#-------------------------------------------------------------------------------------------------#
#Print in degree and out degree of each node in a graph
#in degree is the number of arcs incident to a node 
#out degree is the number of arcs incident from a node - number of ways you can leave a node

def printIn_OutDegree(G):
    edges, nodes = list(G.values()), listOfNodes(G)
    in_ = 0
    for i in nodes:
        for j in edges:
            for k in j:
                if k[0] == i:
                    in_ += 1
        print(f"{i} => In-Degree: {in_}, Out-Degree: {len(G[i])}")
        in_ = 0

# printIn_OutDegree(G)

#-------------------------------------------------------------------------------------------------#
#Print the degree of each node in a Graph

def printDegree(G):
    nodes, degrees = [], []
    for key in G:
        nodes.append(key)
        degrees.append(len(G.get(key)))
    for x in range(len(nodes)):
        print(f"{nodes[x]} => {degrees[x]}")

# printDegree(G)

#-------------------------------------------------------------------------------------------------#
#Return a list of neighbours of a specific node in a graph

def getNeighbors(G, node):
    neighbors = []
    vals = G.get(node)
    for i in range(len(vals)):
        neighbors.append(vals[i][0])
    return neighbors

# print(getNeighbors(G, 0))

#-------------------------------------------------------------------------------------------------#
#A directed Graph is given and a node, return its in-neighbouring nodes

def getInNeighbors(G, node):
    in_ns = []
    for nodes in G:
        for value in G[nodes]:
            if value[0] == node:
                in_ns.append(nodes)
    return in_ns

# print(getInNeighbors(G, 0))

#-------------------------------------------------------------------------------------------------#
#A directed Graph G is given, return its out-neighbouring nodes

def getOutNeighbors(G, node):
    neighbors = []
    vals = G.get(node)
    for i in range(len(vals)):
        neighbors.append(vals[i][0])
    return neighbors

# print(getOutNeighbors(G, 5))

#-------------------------------------------------------------------------------------------------#
#Weighted undirected Graph is given and a node, return its nearest neighbour - neighbour with lowest weight
# G = { 0: [(1, 21), (2, 15)],
# 1: [(0, 21), (2, 10), (3, 70)], 
# 2: [(0, 15), (1, 10), (4, 50)], 
# 3: [(1, 70), (4, 24), (5, 39)], 
# 4: [(3, 24), (2, 50), (5, 99)], 
# 5: [(3, 39), (4, 99)] }
def getNearestNeighbor(G, node):
    check_node = G[node][0][0]
    check_weight = G[node][0][1]
    for i in G[node]:
        if i[1] < check_weight:
            check_weight = i[1]
            check_node = i[0]
    return check_node

# print(getNearestNeighbor(G, 0))

#-------------------------------------------------------------------------------------------------#
#Takes a directed graph G, node 1 and node 2, and return True if node 2 is a neighbour of node 1, else False

# G = { 0: [(1, 1), (2, 1)], 1: [(2, 1), (3, 1)], 2: [(4, 1)], 3: [(4, 1), (5, 1)], 4: [(5, 1)], 5: [] }
def isNeighbor(G, node1, node2):
    for i in G[node1]:
        if i[0] == node2:
            return True
            break
    return False

# print(isNeighbor(G, 1, 0))

#-------------------------------------------------------------------------------------------------#
#Takes a graph G and a node and remove the node and all corresponding edges of the node and returns the updated Graph
#can be directed or undirected both
# G = { 0: [(1, 1), (2, 1)], 
# 1: [(0, 1), (2, 1), (3, 1)], 
# 2: [(0, 1), (1, 1), (4, 1)], 
# 3: [(1, 1), (4, 1), (5, 1)], 
# 4: [(3, 1), (2, 1), (5, 1)], 
# 5: [(3, 1), (4, 1)]}
def removeNode(G, node):
    del G[node]
    for nodes in G:
        for value in G[nodes]:
            if value[0] == node:
                G[nodes].remove((value[0], value[1]))
    return G

# print(removeNode(G, 1))

#-------------------------------------------------------------------------------------------------#
#Takes a graph G and a list of nodes, and removes all those nodes and returns the updated Graph
# G = { 0: [(1, 1), (2, 1)], 
# 1: [(2, 1), (3, 1)], 
# 2: [(4, 1)], 
# 3: [(4, 1), (5, 1)], 
# 4: [(5, 1)], 
# 5: [] }

def removeNodes(G, nodes):
    for i in nodes:
        removeNode(G, i)
    return G

# print(removeNodes(G, [1, 2]))

#-------------------------------------------------------------------------------------------------#
#Takes a graph G and displays its adjacency list
# G = {0: [(1, 1), (2, 1)], 
# 1: [(0, 1), (2, 1), (3, 1)], 
# 2: [(0, 1), (1, 1), (4, 1)], 
# 3: [(1, 1), (4, 1), (5, 1)], 
# 4: [(3, 1), (2, 1), (5, 1)], 
# 5: [(3, 1), (4, 1)] }

def displayGraph(G):
    print("{")
    for node in G:
        print(f"{node}: {G[node]}")
    print("}")

# displayGraph(G)

#-------------------------------------------------------------------------------------------------#
#Takes a graph G and prints the adjacency matrix representation for that graph
#weights are given

# G = { 0: [(1, 21), (2, 15)], 
# 1: [(2, 10), (3, 70)], 
# 2: [(4, 50)], 
# 3: [(4, 24), (5, 39)], 
# 4: [(5, 99)], 
# 5: [] }

def display_adj_matrix(G):
    mat = []
    for node in G:
      mat_zeroes = [0] * len(G)
      for values in G[node]:
        mat_zeroes[values[0] - 1] = values[1]
      mat.append(mat_zeroes)
    print(mat)

# display_adj_matrix(G)
