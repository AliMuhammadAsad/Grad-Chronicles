Stack Operations:
def push(lst, item):
    lst.append(item)
    
def pop(lst):
    return lst.pop()

def top(lst):
    return lst[-1]

-------------------------------------------------------------------------------------------------------------------------------------------------------------

Queue Operations:
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
-------------------------------------------------------------------------------------------------------------------------------------------------------------

Q1) Mirroring -> accepts a queue of strings as a parameter and appends the queue's contents to itself in reverse order, Only 1 stack can be used if needed

def mirror(queue):
    stack = []
    for elem in queue:
        push(stack, elem)
    while not is_empty(stack):
        enQueue(queue, pop(stack))
    return queue

-------------------------------------------------------------------------------------------------------------------------------------------------------------

Q2) Stuttering -> accepts a queue of integers as a parameter and replaces every element with two copies of itself. No other data structure allowed

def stutter(A):
    for x in range(len(A)):
        element = deQueue(A)
        enQueue(A, element), enQueue(A, element)
    return A
