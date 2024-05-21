### Longest Palindrome Sub-Sequence ###
import time
# seq = "bohotbarasapalindromekoisabhi"
# seq = "geeksforgeeks"
seq = "racecar"

## Recursive Approach ##

def lps_rec(seq, i, j):
    if i == j:
        return 1, seq[i]
    
    if seq[i] == seq[j] and i + 1 == j:
        return 2, seq[i] + seq[j]
    
    if seq[i] == seq[j]:
        length, subseq = lps_rec(seq, i + 1, j - 1)
        return length + 2, seq[i] + subseq + seq[j]
    
    l1, subseq1 = lps_rec(seq, i, j - 1)
    l2, subseq2 = lps_rec(seq, i + 1, j)

    if l1 > l2: return l1, subseq1
    else: return l2, subseq2

start = time.time(); lps_r = lps_rec(seq, 0, len(seq) - 1); end = time.time()
print(f"Longest subsequence is '{lps_r[1]}' of length {lps_r[0]}\tTime Taken: {end - start:.6f}\t(Recursion)")


## Dynamic Programming ##
# Memoization #
memo = [[-1 for _ in range(len(seq) + 1)] for _ in range(len(seq) + 1)]
ssmemo = [["" for _ in range(len(seq) + 1)] for _ in range(len(seq) + 1)]
def lps_memo(seq1, seq2, n1, n2):
    if n1 == 0 or n2 == 0:
        return 0, ""
    
    if memo[n1][n2] != -1:
        return memo[n1][n2], ssmemo[n1][n2]
    
    if seq1[n1 - 1] == seq2[n2 - 1]:
        l, s = lps_memo(seq1, seq2, n1 - 1, n2 - 1)
        memo[n1][n2], ssmemo[n1][n2] = l + 1, s + seq1[n1 - 1]
    else:
        l1, s1 = lps_memo(seq1, seq2, n1 - 1, n2)
        l2, s2 = lps_memo(seq1, seq2, n1, n2 - 1)
        if l1 > l2:
            memo[n1][n2], ssmemo[n1][n2] = l1, s1
        else:
            memo[n1][n2], ssmemo[n1][n2] = l2, s2
    
    return memo[n1][n2], ssmemo[n1][n2]

start = time.time(); lps_m = lps_memo(seq, seq[::-1], len(seq), len(seq)); end = time.time()
print(f"Longest subsequence is '{lps_m[1]}' of length {lps_m[0]}\tTime Taken: {end - start:.6f}\t(Memoization)")

# Tabular #
def lps_tab(seq):
    rev = seq[::-1]
    tab = [[0] * (len(rev) + 1) for _ in range(len(seq) + 1)]
    # ssmemo = [["" for _ in range(len(rev) + 1)] for _ in range(len(seq) + 1)]

    for i in range(1, len(seq) + 1):
        for j in range(1, len(rev) + 1):
            if seq[i - 1] == rev[j - 1]:
                tab[i][j] = 1 + tab[i - 1][j - 1]
                # ssmemo[i][j] = ssmemo[i - 1][j - 1] + seq[i - 1]
            else:
                if tab[i - 1][j] > tab[i][j - 1]:
                    tab[i][j] = tab[i - 1][j]
                    # ssmemo[i][j] = ssmemo[i - 1][j]
                else:
                    tab[i][j] = tab[i][j - 1]
                    # ssmemo[i][j] = ssmemo[i][j - 1]
    
    for i in tab:
        print(i)
    return tab[len(seq)][len(rev)] #, ssmemo[len(seq)][len(rev)]

start = time.time(); lps_t = lps_tab(seq); end = time.time()
# print(f"Longest subsequence is '{lps_t[1]}' of length {lps_t[0]}\tTime Taken: {end - start:.6f}\t(Tabular)")
print(f"Longest subsequence is of length {lps_t}\tTime Taken: {end - start:.6f}\t(Tabular)")