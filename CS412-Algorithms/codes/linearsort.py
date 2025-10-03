def linearSort(arr):
    lst = [0 for i in range(len(arr))]
    n_one_index = 0; one_index = len(arr) - 1
    for i in range(len(arr)):
        if arr[i] == -1:
            lst[n_one_index] = -1
            n_one_index += 1
        elif arr[i] == 1:
            lst[one_index] = 1
            one_index -= 1
    arr = lst
    return arr

arr = [1, 0, -1, 1, 0, 1, -1, 0, 1, -1]
arr2 = [-1, -1, -1, 0, 0, 0, 1, 1, 1]
arr3 = [1, 1, 1, 1, -1, -1, -1, 0, 0]
print(linearSort(arr3))