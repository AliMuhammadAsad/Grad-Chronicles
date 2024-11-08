## Simple and Intuitive Dynamic Programming ##
## Top Down Approach ##

def fib_helper(n: int, memo: list[int]) -> int:
    if memo[n] is not None:
        return memo[n]
    if n < 2:
        fib = n
    else:
        fib = fib_helper(n - 1, memo) + fib_helper(n - 2, memo)
    memo[n] = fib
    return fib 

def fib_topdown(n: int) -> int:
    memo = [None for _ in range(n + 1)]
    return fib_helper(n, memo)

print(fib_topdown(0))
print(fib_topdown(1))
print(fib_topdown(2))
print(fib_topdown(3))
print(fib_topdown(4))
print(fib_topdown(5))
print(fib_topdown(6))

## Bottom Up Approach ##
def fibonacci(n):
    fib = [0, 1] + [0]*(n-1)
    for i in range(2, n+1):
        fib[i] = fib[i-1] + fib[i-2]
    return fib[n]

print(fibonacci(6))
4