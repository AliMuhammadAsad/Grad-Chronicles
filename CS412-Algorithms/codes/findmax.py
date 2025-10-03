def findmax(arr, l, h):
    if l == h:
        return arr[l]
    m = (l + h) // 2
    return max(findmax(arr, l, m), findmax(arr, m + 1, h))

a = [2]
ar = [2, 4]
arr = [6, 3, 4, 2]
arrr = [1, 4, 9, 2, 10, 7, 3, 6]

print(findmax(a, 0, len(a) - 1))
print(findmax(ar, 0, len(ar) - 1))
print(findmax(arr, 0, len(arr) - 1))
print(findmax(arrr, 0, len(arrr) - 1))
