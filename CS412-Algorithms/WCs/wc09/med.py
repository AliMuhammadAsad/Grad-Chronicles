inc = "<int><int><;>"
cor = "<int><var><.>"

def minEdits(inc, cor):
    m = len(inc); n = len(cor)
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0: dp[i][j] = j
            elif j == 0: dp[i][j] = i
            elif inc[i - 1] == cor[j - 1]: dp[i][j] = dp[i - 1][j - 1]
            else: dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])

    for i in range(m + 1):
        arr = []
        for j in range(n + 1): arr.append(dp[i][j])
        print(arr)

    return dp[m][n]

edits = minEdits(inc, cor)
print(f"Minimum Edit Distance: {edits}")