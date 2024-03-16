## Rod Cutting Problem Using Dynamic Programming ##

## Top Down Approach - Memoization ##
import math
def memoized_cutrod(p, n):
    r = [0 for _ in range(n + 1)]
    for i in range(0, n + 1):
        r[i] = -math.inf
    return memoized_cutrod_aux(p, n, r)

def memoized_cutrod_aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    if n == 0:
        q = 0
    else:
        q = -math.inf
        for i in range(0, n):
            q = max(q, p[i] + memoized_cutrod_aux(p, n - i - 1, r))
    r[n] = q
    return q 

p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
print(memoized_cutrod(p, 5))

## Bottom Up Approach ##
def bottom_up_cutrod(p, n):
    r = [0 for _ in range(n + 1)]
    r[0] = 0
    for j in range(1, n + 1):
        q = -math.inf
        for i in range(1, j + 1):
            q = max(q, p[i - 1] + r[j - i])
        r[j] = q
    return r[n]

print(bottom_up_cutrod(p, 5))