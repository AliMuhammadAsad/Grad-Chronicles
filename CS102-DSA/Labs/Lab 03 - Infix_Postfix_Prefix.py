Stack Operations

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

--------------------------------------------------------------------------------------------------------------------------

Q1) Infix to Postfix

def Infix_to_Postfix(expression):
    operators = ['+', '-', '*', '/', '(', ')']
    presedence = {'+':1, '-':1, '*':2, '/':2}
    expression = expression.split()
    op_stack, res = [], []
    for x in expression:
        if x not in operators: 
            res.append(x)
        elif x == '(': 
            push(op_stack, x)
        elif x == ')':
            while top(op_stack) != '(': #pops and appends elements in stack till left paranthesis encountered
                res.append(pop(op_stack))
            pop(op_stack) #pops left paranthesis from stack
        else: #x must be an operator
            while not is_empty(op_stack) and top(op_stack) != '(' and presedence[x] <= presedence[top(op_stack)]: 
                res.append(pop(op_stack)) #operands are appended while presedence is lower, stack is not empty, and top element is not (
            push(op_stack, x) 
    while not is_empty(op_stack): #adds all remaining operands to the end of the resultant list
        res.append(pop(op_stack))
    res = " ".join(res) #converts the list to a string with space in between elements
    return res

expression = input()

print(Infix_to_Postfix(expression))

--------------------------------------------------------------------------------------------------------------------------

Q2) Infix to Prefix 

def Infix_to_Prefix(expression):
    operators = ['+', '-', '*', '/', '(', ')']
    presedence = {'+':1, '-':1, '*':2, '/':2}
    expression = expression.split()
    rev_expression, op_stack = [], []
    for x in range(len(expression)): #reverses the expression
        rev_expression.append(pop(expression))
    
    for x in rev_expression: #Infix to Postfix wala code copy paste with smoll changes
        if x not in operators: 
            expression.append(x)
        elif x == ')': 
            push(op_stack, x)
        elif x == '(':
            while top(op_stack) != ')': #pops and appends elements in stack till left paranthesis encountered
                expression.append(pop(op_stack))
            pop(op_stack) #pops left paranthesis from stack
        else: #x must be an operator
            while not is_empty(op_stack) and top(op_stack) != ')' and presedence[x] <= presedence[top(op_stack)]: 
                expression.append(pop(op_stack)) #operands are appended while presedence is lower, stack is not empty, and top element is not (
            push(op_stack, x) 
    while not is_empty(op_stack): #adds all remaining operands to the end of the resultant list
        expression.append(pop(op_stack))
    rev_e_2 = [] #second reversed expression 🙃
    for x in range(len(expression)): #reverses the expression again ughhh 😣
        rev_e_2.append(pop(expression))
    
    rev_e_2 = ' '.join(rev_e_2)
    return rev_e_2

print(Infix_to_Prefix(expression))

--------------------------------------------------------------------------------------------------------------------------

Q3) Prefix Evaluation

def EvaluatePrefix(expression):
    expression = expression.split()
    expression = expression[::-1]
    operandStack = []
    for x in expression:
        if x.isdigit():
            push(operandStack, int(x))
        else:
            a = pop(operandStack)
            b = pop(operandStack)
            if x == '+':
                push(operandStack, a + b)
            elif x == '-':
                push(operandStack, a - b)
            elif x == '*':
                push(operandStack, a * b)
            elif x == '/':
                push(operandStack, a / b)
    return int(pop(operandStack))
                

print(EvaluatePrefix(expression))
