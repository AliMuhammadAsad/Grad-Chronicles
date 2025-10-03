#Determine the three most popular numbers in a list
#Return the list of (number, frequency) pairs sorted by descending order of frequency.
#not allowed to use any built in sorting functions

def sorting(data): #Bubble Sort 
    for i in range(len(data) - 1):
        for j in range(len(data) - i - 1):
            if data[j][1] < data[j+1][1]:
                data[j], data[j+1] = data[j+1], data[j]
    return data

def three_most_popular_numbers(data):
    d, num_freqs = {}, []
    for key in data:
        if key in d:
            d[key] = d[key] + 1
        elif key not in d:
            d[key] = 1
    
    for key in d:
        num_freqs.append((key, d[key]))
    
    vals = sorting(num_freqs)
    return vals[0:3]

lst = [6, 18, 10, 17, 17, 6, 10, 10, 17, 17, 17] #Expected [(17, 5), (10, 3), (6, 2)]
lst_2 = [30, 38, 2, 36, 30, 2, 38, 30, 38, 30] #Expected [(30, 4), (38, 3), (2, 2)]

print(three_most_popular_numbers(lst))
print(three_most_popular_numbers(lst_2))

#---------------------------------------------------------------------------------------------------------------
#Trouble Sort - like bubble sort but examines three adjacent numbers together and swaps the first with the last of the three
#so, 6 6 4, checks if 6 > 4, so swaps 6 with 4 -> 4 6 6 
# 5 4 3, checks if 5 > 3, so swaps 5 with 3 -> 3 4 5
# however, considering 8 9 7, it won't sort correctly.
#Given a list of N integers, determmine whether Trouble sort will successfully sort in non decreasing order or not.
# If it will, return OK, else find the index of the first sorting error after the alg has finished. 

def troubleSort(lst):
    for i in range(len(lst)):
        for j in range(len(lst) - i - 2):
            if lst[j] > lst[j + 2]:
                lst[j], lst[j + 2] = lst[j + 2], lst[j]
    for i in range(len(lst) - 1):
        if lst[i] > lst[i + 1]:
            return i
    return "OK"


lst = [5, 6, 8, 4, 3] #Expected output is OK
lst_2 = [8, 9, 7] #Expected output is 1

print(troubleSort(lst))
print(troubleSort(lst_2))
