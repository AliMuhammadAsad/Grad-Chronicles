#Q1) Unimodel Sequence - this sequence has ascending values, then descending values after a top/peak value such as 1, 3, 5, 9, 6, 2, 1 where the top value or a[t] is 9.
#So a[t] must be greater than a[t-1] and greater than a[t+1]. Write a function that returns the index at top of the sequence.
#The solution must have cost of O(logn) at the worst case.

unimodel_sequence = input().split(" ")
unimodel_sequence = [int(i) for i in unimodel_sequence]
def getTopIndex_UnimodelSequence(unimodel_sequence):
    low, high = 0, len(unimodel_sequence) - 1
    while low < high:
        mid = (low + high) // 2
        if unimodel_sequence[mid] > unimodel_sequence[mid + 1] and unimodel_sequence[mid] > unimodel_sequence[mid - 1]:
            return mid
        elif unimodel_sequence[mid] < unimodel_sequence[mid + 1]:
            low = mid
        elif unimodel_sequence[mid] < unimodel_sequence[mid - 1]:
            high = mid

#------------------------------------------------------------------------------------------------------------------------------------------------------------#

# Q2) Find the Missing number - given a list of n-1 integers such that the list contains sorted numbers in ascending powers of two and no duplicates. One of those integers 
# is missing. Return the missing integer in logn time.

def findMissingNumber(powerTwoList, size):
    if powerTwoList[0] == 2:
        return 1
    low, high = 0, len(powerTwoList) - 1
    while low <= high:
        mid = (low + high) // 2
        if powerTwoList[mid] != 2**mid and powerTwoList[mid - 1] == 2**(mid - 1):
            return (2**mid)
        elif powerTwoList[mid] > 2**mid:
            high = mid - 1
        elif powerTwoList[mid] == 2**mid:
            low = mid + 1
    return (2**(size - 1))

#More efficient and optimized code:
def findMissingNumber(powerTwoList, size):
  low, high = 0, len(powerTwoList) - 1
  while low <= high:
    mid = (low + high) // 2
    if powerTwoList[mid] > 2**mid:
      high = mid - 1
    else:
      low = mid + 1
  return 2**low

#------------------------------------------------------------------------------------------------------------------------------------------------------------#

# Q3) Pair of elements having smallest absolute difference. Given an unsorted list of integers, find the pair of elements that have the smallest absolute difference,
# including multiple pairs if they exist, and returns a list of all the pairs as tuples.

def partition(start, end, arr):
    pivot_index = start 
    pivot = arr[pivot_index]
    while start < end:
        while start < len(arr) and arr[start] <= pivot:
            start += 1
        while arr[end] > pivot:
            end -= 1
        if start < end:
            arr[start], arr[end] = arr[end], arr[start]
    arr[end], arr[pivot_index] = arr[pivot_index], arr[end]
    return end 

def quick_sort(start, end, arr):
    if start < end:
        p = partition(start, end, arr)
        quick_sort(start, p - 1, arr)
        quick_sort(p + 1, end, arr) 
    return arr

def smallest_absdiff_pairs(lst):
    sorted_lst = quick_sort(0, len(lst) - 1, lst)
    res = []
    min_diff = 1000000000000000000000
    for i in range(len(sorted_lst) - 1):
        absdiff = abs(lst[i+1] - lst[i])
        if absdiff == min_diff:
            res.append((lst[i], lst[i+1]))
        elif absdiff < min_diff:
            min_diff, res = absdiff, []
            res.append((lst[i], lst[i+1]))
    return res

#------------------------------------------------------------------------------------------------------------------------------------------------------------#

# Q4) Sort an Array according to absolute difference with given value. Function takes a list of distinct elements and a value "x". The function sorts the values 
# according to their absolute difference with "x". If two or more elements have the same difference, then they are sorted according to their order in list.

def sort_abs_difference(lst, x):
    for i in range(len(lst) - 1):
        for j in range(len(lst) - i - 1):
            if abs(lst[j] - x) > abs(lst[j + 1] - x):
                lst[j], lst[j+1] = lst[j+1], lst[j]
    return lst
