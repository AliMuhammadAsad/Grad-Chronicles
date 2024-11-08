Q1) - Defining Stack Operations
def push(lst, item):
    lst.append(item)
    
def pop(lst):
    return lst.pop()

def top(lst):
    return lst[-1]

def is_empty(lst):
    if len(lst) == 0:
        return True
    else:
        return False

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Q2) - String Reversal using stacks - uses stack operations

def string_reversal(s):
    stack = []
    for x in s:
        push(stack, x)
    if is_empty(stack) == True:
        return ""
    else:
        r_s = ''
        for x in range(len(s)):    
            r_s += pop(stack)
        return r_s

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Q3) - Evaluating postfix using stacks

def postfixEval(exp):
    stack = exp.split()
    val_stack = []
    for x in range(len(stack)):
        if stack[x] == '+':
            a = float(pop(val_stack))
            b = float(pop(val_stack))
            push(val_stack, b + a)
        elif stack[x] == '-':
            a = float(pop(val_stack))
            b = float(pop(val_stack))
            push(val_stack, b - a)
        elif stack[x] == '*':
            a = float(pop(val_stack))
            b = float(pop(val_stack))
            push(val_stack, b * a)
        elif stack[x] == '/':
            a = float(pop(val_stack))
            b = float(pop(val_stack))
            push(val_stack, b / a)
        else:
            push(val_stack, float(stack[x]))
    return pop(val_stack)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Q4) - Queue Operations

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

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Q5) - Generating Binary numbers from 1 to n using Queue where n is an integer

def BinNumsUsingQueue(n):
    q = [] #empty Queue
    enQueue(q, 1) #puts 1 in front of queue
    for i in range(n):
        first = str(deQueue(q)) #takes the first element in the queue
        enQueue(q, first + "0") #adds 0 to the previous first and queues it in the Queue
        enQueue(q, first + "1") #adds 1 to the previous first and queues it in the Queue
        #this works like, first will be 1, then it will be 10 for 2, so 0 gets added to make it 10 and it gets queued, then it will be 11 for 3, so it does that, 
        #after 3 we get 4, which is 100 so it takes 10 from front of queue and puts 0 before it to make it 100 which is 4
        #then is 5 which is 101 so it takes 10 and adds 1 before it to make it 101 which is 5
        #and so on, and it continues
        print(first, end = " ")

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Q6) - Check if a string is a palindrome using both stacks and queues

def is_palindrome(s):
    s = s.lower()
    stack, queue, reversed_stack = [], [], [] 
    for char in s: 
        if char.isalpha():
            push(stack, char)
            enQueue(queue, char)
            
    while not is_empty(stack): 
        push(reversed_stack, pop(stack))
        
    if reversed_stack == queue:
        return True
    else:
        return False
