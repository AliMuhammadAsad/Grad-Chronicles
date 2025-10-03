# Insertion  

def insertion(lst):
    swap = 0
    for i in range(1, len(lst)):
        key = lst[i]
        index = i - 1
        while (index >= 0) and (key < lst[index]):
            lst[index + 1] = lst[index]
            swap +=1
            index-=1
        lst[index + 1] = key
        swap +=1
    return swap

# Selection sort
def selection(lst):
    swap = 0
    for i in range(len(lst)):
        index = i
        for j in range(i+1, len(lst)):
            if lst[index] > lst[j]:
                index = j
        lst[i], lst[index] = lst[index], lst[i]
        swap+=1
    return swap

# Merge Sort

'Taken from GeeksForGeeks, modified to print comparisons.'
swap1 = 0
def mergeSort(arr):
    global swap1
    if len(arr) > 1:
  
         # Finding the mid of the array
        mid = len(arr)//2
  
        # Dividing the array elements
        L = arr[:mid]
  
        # into 2 halves
        R = arr[mid:]
  
        # Sorting the first half
        mergeSort(L)
  
        # Sorting the second half
        mergeSort(R)
  
        i = j = k = 0
  
        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                swap1 +=1
                i += 1
            else:
                arr[k] = R[j]
                swap1 +=1
                j += 1
            k += 1
  
        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            swap1 +=1
            i += 1
            k += 1
  
        while j < len(R):
            arr[k] = R[j]
            swap1 +=1
            j += 1
            k += 1


# QuickSort
swap2 = 0
'Taken from GeeksForGeeks and adapted for comparisons'
def partition(start, end, array):
    global swap2
    pivot_index = start
    pivot = array[pivot_index]
    while start < end:
        while start < len(array) and array[start] <= pivot:
            start += 1
        while array[end] > pivot:
            end -= 1
        if(start < end):
            array[start], array[end] = array[end], array[start]
            swap2 +=1
    array[end], array[pivot_index] = array[pivot_index], array[end]
    swap2 +=1
    return end
def quick_sort(start, end, array):
     
    if (start < end):
        p = partition(start, end, array)
        quick_sort(start, p - 1, array)
        quick_sort(p + 1, end, array)


# Generating random lst
from cProfile import label
import numpy as np
import matplotlib.pyplot as plt

def perms(n):
    perf = {'insertion': [], 'selection': [], 'merge': [], 'quick': []}
    average = []
    for i in range(n//2):
        lst = np.random.permutation(i)
        perf['insertion'].append(insertion(lst))
        perf['selection'].append(selection(lst))
        mergeSort(lst)
        perf['merge'].append(swap1)
    return perf

def main():
    x = [i for i in range(500)]
    y = {'insertion': [], 'selection': [], 'merge': [], 'quick': []}
    for i in range(500):
        perf = perms(i)
        for j in perf:
            if len(perf[j]) == 0:
                y[j].append(0)
            else:
                y[j].append(np.mean(perf[j]))
    return x, y

def plotting(x, y):
    # insertion
    y1 = y['insertion']
    plt.plot(x, y1, label = "insertion", color="red")
    # selection
    y2 = y['selection']
    plt.plot(x, y2, '-.', label="selection", color = "blue")
    # merge
    y3 = y['merge']
    plt.plot(x, y3, '--', label= "merge",  color = "green")
    # quick
    y4 = y['quick']
    plt.plot(x, y4, label = "quick", color = "black")
    plt.xlabel('n - size of input')
    plt.ylabel('No. of comparisons - Average')
    plt.legend()
    plt.show()
x, y = main()
plotting(x, y)