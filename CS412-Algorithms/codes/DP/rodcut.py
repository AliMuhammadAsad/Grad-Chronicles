## Rod Cutting Problem Using Dynamic Programming ##
import math, random
p = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

## Recursive Approach ##
def cutrod_recursive(p, n):
    if n == 0:
        return 0
    q = -math.inf
    for i in range(1, n + 1):
        q = max(q, p[i - 1] + cutrod_recursive(p, n - i))
    return q


## Top Down Approach - Memoization ##
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


# print(cutrod_recursive(p, 5))
# print(memoized_cutrod(p, 5))
# print(bottom_up_cutrod(p, 5))

n = 20
p = [None] * (n + 1)
p[0] = 0
for i in range(1, n + 1):
    p[i] = p[i - 1] + random.randint(0, 5)
    rec, memo, bup = cutrod_recursive(p, i), memoized_cutrod(p, i), bottom_up_cutrod(p, i)
    assert rec == memo == bup, f"Error: n = {i}, rec = {rec}, memo = {memo}, bup = {bup}"
    print(f"n = {i}, rec = {rec}, memo = {memo}, bup = {bup}")