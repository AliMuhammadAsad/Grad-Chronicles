#Who is the class monitor
#N-students labeled from  1 - N and one student is the class monitor.
#Class monitor trusts no one, everyone trusts the class monitor

def generateTrustGraph(N, ListofEdges): #generates a trust graph in the form of adjacency list and returns the graph
    G = {}
    for node in range(1, N+1):
        G[node] = []
    for edges in ListofEdges:
        G[edges[0]].append(edges[1])
    return G

def findMonitor(G): #Takes the graph as input and identifies class monitor. If doesn't exist, then return -1.
    for student in G:
        if len(G.get(student)) == 0:
            return student
    return -1

n = 4
listofEdges = [(1, 3), (1, 4), (2, 3), (2, 4), (4, 3)]
#expected output is 3

n2 = 3
listofEdges2 = [(1, 3), (2, 3), (3, 1)]
#expected output is -1

G = generateTrustGraph(n, listofEdges)
print(findMonitor(G))

G2 = generateTrustGraph(n2, listofEdges2)
print(findMonitor(G2))

#---------------------------------------------------------------------------------------------------------------
#Attack Most Critical Node
#Identify the node with most number of connections in a graph
#and disrupt that network by removing the node and all its connections

def removeMostCriticalNode(G):
    check, node = 0, int() #check for number of connections of a node
    for key in G:
        if len(G[key]) > check:
            check = len(G[key])
            node = key
    del G[node]
    for nodes in G:
        for connection in G[nodes]:
            if connection == node:
                G[nodes].remove(node)
    return G

#---------------------------------------------------------------------------------------------------------------

#Star Graphs
#star graph is an undirected graph in which n-1 nodes have degree 1 and a single node has degree n-1 (center node)
#Find if the given graph is a star graph or not

def generateGraph(N, edgesList):
    G = {}
    for n in range(1, N + 1):
        G[n] = []
    for node, edge in edgesList:
        G[node].append(edge)
        G[edge].append(node)
    return G
        

def isStarGraph(G): #Returns True if the graph else False
    lst_ones, lst_center = [], []
    for node in G:
        if len(G[node]) == 1:
            lst_ones.append(node)
        elif len(G[node]) == (len(G) - 1):
            lst_center.append(node)
        elif len(G[node]) != 1 or len(G[node]) != (len(G) - 1):
            return False    
    if len(lst_ones) == (len(G) - 1) and len(lst_center) == 1:
        return True
    else:
        return False

def StarGraphCenter(G): #Takes a star graph as adjacency list and return the center
    for node in G:
        if len(G[node]) == (len(G) - 1):
            return node


n = 4
edges = [(1, 2), (2, 3), (4, 2)] 
#G = {1 : [2], 2 : [1, 3, 4], 3 : [2], 4 : [2]} #returns True with center 2

# n = 5
# edges = [(1, 2), (5, 1), (1, 3), (1, 4)] 
#G = {1 : [2, 5, 3, 4], 2 : [1], 5 : [1], 3 : [1], 4 : [1] } #Returns True with center 1

# n = 4
# edges = [(1, 2), (1, 3), (4, 2)]
# G = {1 : [2, 3], 2 : [1, 4], 3 : [1] , 4 : [2] } #Returns False

G = generateGraph(n, edges)
print(G)
print(isStarGraph(G))
if isStarGraph(G) == True:
    print(StarGraphCenter(G))