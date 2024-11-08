## The 0/1 Knapsack Problem ##
import time
values = [30, 14, 16, 9, 10, 20, 13, 15]
weights = [6, 3, 4, 2, 1, 5, 3, 7]
W = 50
W = 50


## Brute Force / Recursive Approach ##

def knapsack_recursive(W: int, weights: list, values: list, n: int):
    # Base Case: If there are no items left to consider or the knapsack is full
    if n == 0 or W == 0:
        return 0
    
    # If the weight of the nth item is more than the knapsack capacity, then the item cannot be included
    if weights[n - 1] > W:
        return knapsack_recursive(W, weights, values, n - 1)
    # Otherwise, return the maximum of two cases (nth item included, nth item not included)
    else:
        return max(values[n - 1] + knapsack_recursive(W - weights[n - 1], weights, values, n - 1), knapsack_recursive(W, weights, values, n - 1))

start = time.time(); kr = knapsack_recursive(W, weights, values, len(values)); end = time.time()
print(f"Maximum Value (Recursive): {kr}\tTime Taken: {end - start:.6f}")  

def knapsack_recursive_repetition(W: int, weights: list, values: list, n: int):
    # Base Case: If there are no items left to consider or the knapsack is full
    if n == 0 or W == 0:
        return 0
    
    # If the weight of the nth item is more than the knapsack capacity, then the item cannot be included
    if weights[n - 1] > W:
        return knapsack_recursive_repetition(W, weights, values, n - 1)
    # Otherwise, return the maximum of two cases (nth item included, nth item not included)
    else:
        return max(values[n - 1] + knapsack_recursive_repetition(W - weights[n - 1], weights, values, n), knapsack_recursive_repetition(W, weights, values, n - 1))

start = time.time(); krr = knapsack_recursive_repetition(W, weights, values, len(values)); end = time.time()
print(f"Maximum Value (Recursive with Repetition): {krr}\tTime Taken: {end - start:.6f}")

## Dynamic Programming Approach ##

# Memoization #

def knapsack_memo(W: int, weights: list, values: list, n: int):
    # Base Case
    if n == 0 or W == 0:
        return 0
    
    # If the value is already calculated, return it
    if memo[n][W] != -1:
        return memo[n][W]
    
    # If the weight of the nth item is more than the knapsack capacity, then the item cannot be included
    if weights[n - 1] <= W:
        memo[n][W] = max(values[n - 1] + knapsack_memo(W - weights[n - 1], weights, values, n - 1), knapsack_memo(W, weights, values, n - 1))
        return memo[n][W]
    # Otherwise, return the value of the previous item
    else:
        memo[n][W] = knapsack_memo(W, weights, values, n - 1)
        return memo[n][W]

memo = [[-1 for i in range(W + 1)] for j in range(len(values) + 1)]
start = time.time(); km = knapsack_memo(W, weights, values, len(values)); end = time.time()
print(f"Maximum Value (Memoization): {km}\tTime Taken: {end - start:.6f}")

def knapsack_memo_repetition(W: int, weights: list, values: list, n: int):
    # Base Case
    if n == 0 or W == 0:
        return 0
    
    # If the value is already calculated, return it
    if memo[n][W] != -1:
        return memo[n][W]
    
    # If the weight of the nth item is more than the knapsack capacity, then the item cannot be included
    if weights[n - 1] <= W:
        memo[n][W] = max(values[n - 1] + knapsack_memo_repetition(W - weights[n - 1], weights, values, n), knapsack_memo_repetition(W, weights, values, n - 1))
        return memo[n][W]
    # Otherwise, return the value of the previous item
    else:
        memo[n][W] = knapsack_memo_repetition(W, weights, values, n - 1)
        return memo[n][W]
    
memo = [[-1 for i in range(W + 1)] for j in range(len(values) + 1)]
start = time.time(); kmr = knapsack_memo_repetition(W, weights, values, len(values)); end = time.time()
print(f"Maximum Value (Memoization with Repetition): {kmr}\tTime Taken: {end - start:.6f}")

# Tabulation #
def knapsack_bup(W: int, weights: list, values: list, n: int):
    K = [[0 for i in range(W + 1)] for j in range(n + 1)]

    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif weights[i - 1] <= w:
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    return K[n][W]

start = time.time(); kb = knapsack_bup(W, weights, values, len(values)); end = time.time()
print(f"Maximum Value (Tabulation): {kb}\tTime Taken: {end - start:.6f}")

def knapsack_bup_repetition(W: int, weights: list, values: list, n: int):
    K = [[0 for i in range(W + 1)] for j in range(n + 1)]

    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif weights[i - 1] <= w:
                K[i][w] = max(values[i - 1] + K[i][w - weights[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    return K[n][W]

start = time.time(); kbr = knapsack_bup_repetition(W, weights, values, len(values)); end = time.time()
print(f"Maximum Value (Tabulation with Repetition): {kbr}\tTime Taken: {end - start:.6f}")