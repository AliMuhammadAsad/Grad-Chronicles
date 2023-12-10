Q1) Paranthetical - Checks if a given sequence of brackets can be corrected by moving at most 1 bracket from its position. Returns Yes if it can else returns no
#Move at most 1 bracket from its place
#Reversing any bracket is not allowed
#Only round brackets => '(' or ')'

seq = input()

def isCorrect(seq):
    if len(seq) % 2 == 1: #if odd sequence, then can't be corrected so returns No 
        return "No"
    else:
        count = 0 #counter to check the times closing and opening brackets occur for comparison
        for x in seq:
            if x == '(':
                count += 1 #count +1 on each opening bracket
            elif x == ')':
                count -= 1 #count -1 on each closing bracket
                if count == -2: #if count = -2, then 2 brackets at the wrong place, thus can't be corrected and breaks to return No
                    break
        if count == 0: #Correct as count = 0, so returns Yes
            return "Yes"
        else: 
            return "No" #returns No for all other values of count as then it can't be corrected if the count is too high even 

print(isCorrect(seq))

----------------------------------------------------------------------------------------------------------------------------------------------------

Q2) Balanced Braces - Checks if the given brackets are balanced in the sequence or not - returns False if not balanced, returns True if balanced
#Uses only 1 stack and stack ADT operations
#Counters of any sort are not allowed to count the brackets

s=input()

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
    
def balanced_braces(s):
    if len(s) % 2 == 1: #returns False if length of sequence is odd as it must be unbalanced for odd
        return False
    else:
        opening_braces = ['(', '[', '{']
        stack = []
        for x in s:
            if x in opening_braces: #pushes opening braces in the stack
                push(stack, x)
            else:
                if is_empty(stack): #if stack is empty, then the braces are not balanced as there must've been some opening brace for it to reach a closing brace, thus returns False
                    return False
                brace = pop(stack) #takes the top value from stack (pops) for comparison and checks for each case, if it does not match, any of them, false is returned as there is no opening brace for the closing brace at hand 
                if brace == '(': 
                    if x != ')': 
                        return False
                if brace == '[':
                    if x != ']':
                        return False
                if brace == '{':
                    if x != '}':
                        return False
        if not is_empty(stack): #if stack is still not empty after running through the loop, then the braces must not be balanced, thus returns False, but if it is empty at this point, the braces are balanced
            return False
        else:
            return True


print(balanced_braces(s))
