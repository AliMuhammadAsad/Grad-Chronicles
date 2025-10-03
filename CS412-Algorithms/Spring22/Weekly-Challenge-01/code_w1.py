from hashlib import new
import itertools
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

"""
    Run this file in any python terminal and enter the input when asked. Uncomment the main function. 
"""

def permutations(lst):
    return list(itertools.permutations(lst))

def find_updates(x):
    m = max(x)
    if x[-1] == m:
        return 0
    L = 0
    current = x[-1]
    index = -1
    while (current != m):
        index-=1
        if current < x[index]:
            current = x[index]
            L+=1
    return L

def find_expected(counts, n, x):
    res = 0
    for i in range(n):
        res += i * (counts[i]/x)
    return res

def main():
    n = int(input("Input the value of n: "))
    lst = [i for i in range(1, n+1)]
    perms = permutations(lst)
    print("The number of permutations are: ", len(lst))
    L_list = []
    for perm in perms:
        L = find_updates(perm)
        L_list.append(L)
    counts = []
    for i in range(n):
        print("Number of Permutations where L = ", i, ": ",  L_list.count(i))
        counts.append(L_list.count(i))
    avg = find_expected(counts, n, len(perms))
    print("Expected value of L, E(L), is: ",avg)

# ------------------------------------------------------------------------------------
'''Code for the Pattern'''

def find_pattern_exp(L, n):
    avg = 0
    dividend = 1
    for i in range(1,n+2):
        dividend = dividend * i
    print("dividend: ", dividend)
    for i in range(n+1):
        avg += i * (L[i]/dividend)
    return avg

def new_L(L, n):
    L.insert(0,0)
    L_lst = []
    for i in range(1, n+1):
        temp = (n*L[i]) + L[i-1]
        L_lst.append(temp)
    L_lst.append(1)

    # print("The expected value is: ", find_pattern_exp(L_lst, n))
    return L_lst, find_pattern_exp(L_lst, n)

def graphing(x, y):
    plt.yticks(np.arange(10))
    plt.plot(x, y, markersize=2, color='red', marker='o')
    plt.title("Average case analysis of the value of L", fontsize=14)
    plt.xlabel('N', fontsize=14)
    plt.ylabel('Expected Value of L', fontsize=14)
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    # main()
    y = []
    x = []
    temp = [1]
    for i in range(1, 200): # Change this if needed
        x.append(i)
        temp, avg = new_L(temp, i)
        y.append(avg)
    graphing(x, y)