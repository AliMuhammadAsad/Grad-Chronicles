## Longest Common Subsequence ##

## Memoization ##
def lcs_memo(X, Y, m, n, memo):
    if m == 0 or n == 0:
        return "", 0
    
    if memo[m][n] != -1:
        return memo[m][n]
    
    if X[m - 1] == Y[n - 1]:
        lcs, length = lcs_memo(X, Y, m - 1, n - 1, memo)
        memo[m][n] = (lcs + X[m - 1], length + 1)
        return memo[m][n]
    
    lcs1, length1 = lcs_memo(X, Y, m - 1, n, memo)
    lcs2, length2 = lcs_memo(X, Y, m, n - 1, memo)
    if length1 > length2: memo[m][n] = (lcs1, length1)
    else: memo[m][n] = (lcs2, length2)

    return memo[m][n]

X = input("Enter your String X:"); m = len(X)
Y = input("Enter your String Y:"); n = len(Y)

memo = [[-1 for i in range(n + 1)] for j in range(m + 1)]
lcs, length = lcs_memo(X, Y, m, n, memo)
print(f"(Memoization)\tLength of LCS is {length} and the sequence is {lcs}")


## Tabulation / Bottom Up ##
def lcs_tab(X, Y, m, n):
    tab = [[None] * (n + 1) for i in range(m+1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0: tab[i][j] = ("", 0)
            elif X[i - 1] == Y[j - 1]:
                lcs, length = tab[i - 1][j - 1]
                tab[i][j] = (lcs + X[i - 1], 1 + length)
            else:
                lcs1, length1 = tab[i - 1][j]; lcs2, length2 = tab[i][j - 1]
                if length1 > length2: tab[i][j] = (lcs1, length1)
                else: tab[i][j] = (lcs2, length2)
    return tab[m][n]

lcs, length = lcs_tab(X, Y, m, n)
print(f"(Tabulation)\tLength of LCS is {length} and the sequence is {lcs}")
                