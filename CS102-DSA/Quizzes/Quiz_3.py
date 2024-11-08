#Find Missing Numbers in a list using binary search
#Given a list of n-1 integers ranging from 1 - n in descending order
#Use binary search to return the missing integer from the list

def findMissingNumber(numberlist):
    if numberlist[-1] != 1:
        return 1
    elif numberlist[0] == len(numberlist):
        return numberlist[0] + 1
    else:
        low, high = 0, len(numberlist) - 1
        while low <= high:
            mid = (low + high) // 2
            if (numberlist[mid - 1] - numberlist[mid] != 1):
                return numberlist[mid] + 1
            elif (numberlist[mid] - numberlist[mid + 1] != 1):
                return numberlist[mid] - 1
            elif numberlist[mid] == mid + 1:
                high = mid
            else:
                low = mid

num = [4, 3, 2, 1] #expected output is 5
num_2 = [4, 3, 2] #expected output is 1
num_3 = [6, 5, 3, 2, 1] #expected output is 4

print(findMissingNumber(num))
print(findMissingNumber(num_2))
print(findMissingNumber(num_3))

#------------------------------------------------------------------------------------------------------------------------------------------------#

#Finding the position of the last zero using binary search
#Given a list A of length n, the list contains a series of 0s followed by 1s
#Find the location of the last 0, A[k] = 0 and A[k+1] = 1
#There is at least 1 zero and 1 one in the list and list will not be empty

def findLastZeroLocation(A):
    low, high = 0, len(A) - 1
    while low < high:
        mid = (low + high) // 2
        if A[mid] == 0 and A[mid + 1] == 1:
            return mid + 1
        elif A[mid] == 1 and A[mid - 1] == 0:
            return mid
        elif A[mid + 1] == 0:
            low = mid
        elif A[mid - 1] == 1:
            high = mid


lst = [0, 0, 0, 0, 0, 1]
print(findLastZeroLocation(lst))

#------------------------------------------------------------------------------------------------------------------------------------------------#

#Given a list which has a sequence of 0s followed by a sequence of 1s followed by a sequence of 2s
#Use binary search to find the total number of 1s in the list

def span_of_ones(lst):
    low, high = 0, len(lst) - 1
    while low <= high:
        mid = (low + high) // 2
        if (lst[low + 1] == 1 and lst[low] == 0) and (lst[high - 1] == 1 and lst[high] == 2):
            return high - low - 1
        if lst[mid] == 1 and lst[mid - 1] == 0:
            low = mid - 1
        if lst[mid] == 1 and lst[mid + 1] == 2:
            high = mid + 1
        else:
            if lst[low + 1] != 1:
                low += 1
            if lst[high - 1] != 1:
                high -= 1


lst = [0, 0, 0, 0, 1, 1, 2, 2, 2] #expected output 2
lst_2 = [0, 1, 1, 1, 2, 2] #expected output 3

print(span_of_ones(lst))
print(span_of_ones(lst_2))
