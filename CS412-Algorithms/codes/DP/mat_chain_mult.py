## Matrix Chain Multiplication ##
import time
# chain = [1, 2, 3, 4, 3] # There are 4 matrices of dimensions 1x2, 2x3, 3x4, 4x3

# chain = [50, 20, 1, 10, 100] # Example from the book, expected = 7000

chain = [50, 20, 1, 10, 100, 1000, 20, 70, 90, 80, 60, 40, 30]
n = len(chain)

## Recursive Brute Force Approach ##

def MatChainRecursive(chain: list, i: int, j: int):
    if i == j:
        return 0
    
    mini = float('inf')
    for k in range(i, j):
        count = MatChainRecursive(chain, i, k) + MatChainRecursive(chain, k + 1, j) + chain[i - 1]*chain[k]*chain[j]
        mini = min(mini, count)
    return mini

start = time.time(); mcr = MatChainRecursive(chain, 1, n - 1); end = time.time()

print(f"Minimum number of multiplications (Recursive): {mcr}\tTime Taken: {end-start:.6f}")


## Dynamic Programming Approach ##
# Memoization #
memo = [[-1 for i in range(n)] for j in range(n)]
def MatChainMult_Memo(chain, i, j):
    if i == j:
        return 0
    
    if memo[i][j] != -1:
        return memo[i][j]
    
    memo[i][j] = float('inf')
    for k in range(i, j):
        count = MatChainMult_Memo(chain, i, k) + MatChainMult_Memo(chain, k + 1, j) + chain[i - 1]*chain[k]*chain[j]
        memo[i][j] = min(memo[i][j], count)
    return memo[i][j]

start = time.time(); mcm = MatChainMult_Memo(chain, 1, n - 1); end = time.time()

print(f"Minimum number of multiplications (Memoization): {mcm}\tTime Taken: {end-start:.6f}")

# Tabular #

def MatChainTab(chain):
    n = len(chain)
    m = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(1, n):
        m[i][i] = 0
    
    for l in range(2, n):
        for i in range(1, n - l + 1):
            j = i + l - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                q = m[i][k] + m[k + 1][j] + chain[i - 1]*chain[k]*chain[j]
                m[i][j] = min(m[i][j], q)

    return m[1][n - 1]

start = time.time(); mcm = MatChainTab(chain); end = time.time()

print(f"Minimum number of multiplications (Tabular): {mcm}\tTime Taken: {end - start:.6f}")