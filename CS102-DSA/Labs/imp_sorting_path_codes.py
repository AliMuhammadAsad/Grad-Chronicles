#BUBBLE SORT

def bubblesort(L):
    for i in range(len(L)):
        count=False
        for j in range(len(L)-i-1):
            if L[j]>L[j+1]:
                count=True
                L[j],L[j+1]=L[j+1],L[j]
        if count==False:
            break
    return L

#INSERTION SORT

def InsertionSort(L):
    for front in range(1,len(L)):
        i=front-1
        while i>=0 and L[front]<L[i]:
            i-=1
        L.insert(i+1,L[front])
        del(L[front+1])
    return L   

#SELECTION SORT

def SelectionSort(L):
	for front in range(len(L)):
		min = front
		for j in range(front, len(L), 1):
			if L[j] < L[min]:
				min = j
		L[front], L[min] = L[min], L[front]
	return L

#MERGE SORT

def merge(A,B):
    i=0
    j=0
    c=[]
    while i<len(A) and j<len(B):
        if A[i]<B[j]:
            c.append(A[i])
            i+=1
        else:
            c.append(B[j])
            j+=1
        if i==len(A):
            c+=B[j:]
        if j==len(B):
            c+=A[i:]
    return c                

def mergeSort(L):
    if len(L)==1:
        return L
    else:
        mid=(len(L))//2 
        L1, L2 = mergeSort(L[0:mid]), mergeSort(L[mid:])
        return merge(L1, L2) 

#QUICK SORT

def quickSort(L):
    if len(L)<=1:
        return L
    else:
        pivot=L[0]
        L1,L2=partition(L,pivot)
        S1,S2=quickSort(L1),quickSort(L2) 
        return S1+[pivot]+S2

def partition(L,pivot):
    L.remove(pivot)
    L1,L2=[],[]
    for i in L:
        if  i>pivot:
            L2.append(i)
        else:
            L1.append(i)
    return L1,L2

#BFS

def bfs(G, s):
    Q = []
    lst=[]
    enqueue(Q, s)
    visited = addNodes(G, False) #A new dictionary which has nodes set to False
    while len(Q) > 0 :
        u = dequeue(Q)
        if visited[u] == False:
            visited[u] = True
            push(lst,u)
            children = out_edges(G,u)
            for child in children:
                enqueue(Q, child)
    return lst

#DFS

def dfs(G,s):
    S=[]
    push(S,s)
    lst=[] 
    visited=addNodes(G,False)  #A new dictionary which has nodes set to False 
    while len(S)>0:
        u=pop(S)
        if visited[u]==False:
            push(lst,u) 
            visited[u]=True
            children=out_edges(G,u)[::-1] 
            for child in children:
                push(S,child)
    return lst 

#DIJKSTRA

import math
def getShortestPath (graph, s, e):
    PQ=[]
    enqueue(PQ,(s,0))                         #Enqueue for Priority Queue
    Dist=addNodes(graph,math.inf)
    Dist[s]=0

    Prev=addNodes(graph, None)

    while len(PQ)>0:
        u=dequeue(PQ)
        if u[0]==e:
            break
        children=out_edges(graph,u[0])
    
        for child,weight in children:
            alt=Dist[u[0]]+weight
            if alt<Dist[child]:
                Dist[child]=alt
                Prev[child]=u[0]
                enqueue(PQ,(child,alt))
    path=[]
    x=e
    while x!=None:
        path.append(x)
        x=Prev[x] 
    path.reverse()
    steps = []
    for i in range(len(path)):
        if path[i]!= e:
            steps+=[(path[i],path[i+1])] 
    return steps 

#MST Prims

import math 
def MSTPrims(G):
    s=list(G.keys())[0] 
    PQ = []
    enqueue(PQ,(s,0))                          #Enqueue for Priority Queue
    MST = addnodes(G,None)
    Included = addnodes(G,False)
    dist = addnodes(G,math.inf)
    while len(PQ) >0:
        u = dequeue(PQ)
        u = u[0]
        Included[u] = True
        children = G[u]
        for child,weight in children:
            if not Included[child] and weight < dist[child]:
                dist[child] = weight
                MST[child] = u
                enqueue(PQ,(child,weight))  
    lst = []
    for i in MST:   
        if i != s :
            x = MST[i]
            y = dist[i]
            lst.append((x,i,y))
    return lst