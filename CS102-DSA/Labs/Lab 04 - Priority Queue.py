Q1) Priority Queue Implementation - implement a priority queue in descending order, and a dequeue function to return and pop the front of it

def Enqueue(queue, item, priority):
    element = (item, priority)
    if len(queue) == 0:
        queue.append(element)
    elif queue[-1][1] >= priority:
        queue.append(element)
    else:
        for x in range(len(queue)):
            if priority > queue[x][1]:
                queue.insert(x, element)
                break
                
def Dequeue(queue):
    element = queue.pop(0)
    return element[0]

-----------------------------------------------------------------------------------------------------------------------------------------------------

Q2) HU - Help Desk -> takes some information with its priority, enqueues it according to priority and returns it in order of priority

def Enqueue(queue, item, priority):
    element = (item, priority)
    if len(queue) == 0:
        queue.append(element)
    elif queue[-1][1] >= priority:
        queue.append(element)
    else:
        for x in range(len(queue)):
            if priority > queue[x][1]:
                queue.insert(x, element)
                break
                
def Dequeue(queue):
    element = queue.pop(0)
    return element[0]

queue = []
Enqueue(queue,"AC Not working in Tariq Rafi", 5)
Enqueue(queue,"Password Change Issue", 4)
Enqueue(queue,"Need Installation on laptop", 3)
Enqueue(queue,"Need license", 1)
Enqueue(queue,"Lab PCs Setup", 3)
Enqueue(queue,"Login Issue", 4)

for x in range(len(queue)):
    print(Dequeue(queue))

-----------------------------------------------------------------------------------------------------------------------------------------------------

Q3) Interleave - Interleaves one half of a queue with its second half 
#Only one additional stack can be used, only use the same queue as given

import ast
lst = input()
lst = ast.literal_eval(lst)

#Queue Operations
def enQueue(lst, data):
    lst.append(data)
    
def deQueue(lst):
    return lst.pop(0)

def front(lst):
    return lst[0]

def is_empty(lst):
    if len(lst) == 0:
        return True
    else:
        return False
    
#Stack Operations
def push(lst, item):
    lst.append(item)
    
def pop(lst):
    return lst.pop()

def top(lst):
    return lst[-1]

def InterLeaveQueue(lst):
    stack = [] 
    for x in range(int(len(lst) / 2)): #half elements are enqueued back at the end -> q = 3, 4, 1, 2
        enQueue(lst, deQueue(lst))
        
    for x in range(int(len(lst) / 2)): #half elements are sent to stack -> q = 1, 2 & s = 4, 3
        push(stack, deQueue(lst))
        
    while not is_empty(stack): #stack elements are enqueued back in the queue, but with reverse order, so q = 1, 2, 4, 3
        enQueue(lst, pop(stack))
    for x in range(int(len(lst) / 2)): #half elements are enqueued back at the end -> q = 4, 3, 1, 2
        enQueue(lst, deQueue(lst))
    for x in range(int(len(lst) / 2)): #half elements are pushed to stack -> q= 1, 2 & s = 3, 4
        push(stack, deQueue(lst))
    #The stack now has the second half in proper order as needed, queue has first half in order, so enqueue them back one by one in the queue to get interleave
    while not is_empty(stack):
        enQueue(lst, deQueue(lst))
        enQueue(lst, pop(stack))
    return lst    
    
print(InterLeaveQueue(lst))
