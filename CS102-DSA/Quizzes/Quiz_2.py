#Q1 - Base Converter - Use stack to convert a given denary number to a number of base 'n'
#a single stack can be used only
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

def base_converter(n, base):
    stack = []
    while n > 0:
        rem = n % base
        if rem == 10:
            rem = "A"
        elif rem == 11:
            rem = "B"
        elif rem == 12:
            rem = "C"
        elif rem == 13:
            rem = "D"
        elif rem == 14:
            rem = "E"
        elif rem == 15:
            rem = "F"
        push(stack, rem)
        n = n // base
    s = str()
    while not is_empty(stack):
        s += str(pop(stack))
    return s

n = int(input("Please enter a decimal number: "))
base = int(input("Please enter the base in which you want to convert: "))

print(base_converter(n, base))

#------------------------------------------------------------------------------------------------------------------------------------------------#

#Q2 - Decode a string s - a letter(s) has a number before it, it must repeat it that many times
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

s1 = "3[a]2[bc]"
s2 = "3[a2[c]]"
s3 = "2[abc]3[cd]ef"

def decodestring(s):
    res, stack = str() , []
    ints = "123456789"
    for x in s:
        temp_s = str()
        if x != "]":
            push(stack, x)
        elif x == ']':
            while top(stack) != "[" and not is_empty(stack):
                temp_s += pop(stack)
            pop(stack)
            if top(stack) in ints:
                push(stack, int(pop(stack)) * temp_s)
    while not is_empty(stack):
        res += pop(stack)
    return res[:: -1]


print(decodestring(s1))
print(decodestring(s2))
print(decodestring(s3))
