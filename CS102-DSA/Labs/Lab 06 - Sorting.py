Q1) Selection Sort
def selection_sort(lst):
    for i in range(len(lst)):
        min_index = i
        for j in range(i, len(lst)):
            if lst[min_index] > lst[j]:
                min_index = j
        lst[i], lst[min_index] = lst[min_index], lst[i]
        print(lst)

---------------------------------------------------------------------------------------------------------------------------------------------------------

Q2) Insertion Sort
def insertion_sort(lst):
    for i in range(1, len(lst)):
        j = i
        while j > 0 and lst[j] < lst[j - 1]:
            lst[j], lst[j - 1] = lst[j - 1], lst[j]
            j -= 1
        print(lst)

---------------------------------------------------------------------------------------------------------------------------------------------------------

Q3) Bubble Sort
def bubble_sort(lst):
    if len(lst) == 1:
        print(lst)
    for i in range(len(lst)-1):
        for j in range(len(lst) - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]
        print(lst)

---------------------------------------------------------------------------------------------------------------------------------------------------------

Q4) Sort Matrix by row - use selection sort to sort a matrix by its rows (sort rows inside the matrix)
def selection_sort(lst):
    for i in range(len(lst)):
        min_index = i
        for j in range(i, len(lst)):
            if lst[min_index] > lst[j]:
                min_index = j
        lst[i], lst[min_index] = lst[min_index], lst[i]
    return(lst)
    
def sort_matrix_by_row(lst):
    for x in range(len(lst)):
        lst[x] = selection_sort(lst[x])
    return lst

---------------------------------------------------------------------------------------------------------------------------------------------------------

Q5) Sort Matrix by column - use selection sort to sort a matrix using its columns - column number is given, sort the rows by given column number

def sort_matrix_by_columnNumber(lst, column):
    for i in range(len(lst)):
        min_index = i
        for j in range(i, len(lst)):
            if lst[min_index][column] > lst[j][column]:
                min_index = j
        lst[i], lst[min_index] = lst[min_index], lst[i]
    return(lst)

---------------------------------------------------------------------------------------------------------------------------------------------------------

Q6) Sorting rectangle records
Use insertion sort to sort the given information about some rectangles in dictionaries
Record title to be used as key for sorting

def sort_rectangles(rectangle_records, record_title):
    for i in range(1, len(rectangle_records)):
        j = i
        while j > 0 and rectangle_records[j][record_title] < rectangle_records[j - 1][record_title]:
            rectangle_records[j], rectangle_records[j - 1] = rectangle_records[j - 1], rectangle_records[j]
            j -= 1
    return(rectangle_records)
