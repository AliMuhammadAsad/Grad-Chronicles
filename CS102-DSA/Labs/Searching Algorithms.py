from re import search


Binary Search
#Done on a sorted list.
#Works by constantly halving the list and checking for value to search in upper or lower half

a = [0, 9, 12, 13, 22]
#key = int(input("Enter integer: "))
key = 12

def binary_search(a, key):
    low, high = 0, len(a) - 1 #low index and high index (0 and length - 1 to iterate respectively)

    while low <= high: #if low becomes greater than high, this means that key does not exist in list thus exits and returns prompt
        mid = (low+high) // 2 
        curr = a[mid] #current value 
        if curr == key: 
            return(mid)
        elif curr > key:
            high = mid - 1
        elif curr < key:
            low = mid + 1
    return("Key not found")

print(binary_search(a, key)) #returns only the index of the key for now, if the key exists
