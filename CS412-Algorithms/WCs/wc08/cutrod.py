## Recursive Approach ##
def cut_rod(p, n):
    if n == 0:
        return 0
    q = -1e21
    for i in range(1, n + 1):
        q = max(q, p[i - 1] + cut_rod(p, n - i))
    return q

## Memoized / Top Down Approach ##
def cut_rod_memoize(p, n):
    r = [0 for _ in range(n + 1)]
    for i in range(0, n + 1):
        r[i] = -1e9
    return cut_rod_memoized_aux(p, n, r)

def cut_rod_memoized_aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    if n == 0:
        q = 0
    else:
        q = -1e21
        for i in range(1, n + 1):
            q = max(q, p[i - 1] + cut_rod_memoized_aux(p, n - i, r))
    r[n] = q
    return q

## Bottom Up - Approach ##
def cut_rod_bottom_up(p, n):
    r = [0 for _ in range(n + 1)]
    r[0] = 0
    for j in range(1, n + 1):
        q = -1e21
        for i in range(1, j + 1):
            q = max(q, p[i - 1] + r[j - i])
        r[j] = q
    return r[n]
