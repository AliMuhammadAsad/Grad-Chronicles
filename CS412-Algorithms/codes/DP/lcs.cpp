/* Longest Common Subsequence Using Dynamic Programming */

/* Memoization */
#include <bits/stdc++.h>
using namespace std;

int lcs_memo(string X, string Y, int m, int n, vector<vector<int>> &memo){
    if(m == 0 || n == 0) 
        return 0;
    if(X[m - 1] == Y[n - 1]) 
        return memo[m][n] = 1 + lcs_memo(X, Y, m - 1, n - 1, memo);

    if(memo[m][n] != -1) 
        return memo[m][n];
    
    return memo[m][n] = max(lcs_memo(X, Y, m - 1, n, memo), lcs_memo(X, Y, m, n - 1, memo));
}

/* Tabulation / Bottom Up */
int lcs_tab(string X, string Y, int m, int n){
    int tab[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0) 
                tab[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) 
                tab[i][j] = tab[i - 1][j - 1] + 1;
            else 
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
        }
    }
    return tab[m][n];
}

int main(){
    string X, Y;
    cout << "Enter your first string: ";
    cin >> X;
    cout << "Enter your second string: ";
    cin >> Y;
    int m = X.length(); int n = Y.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    cout << "(Memoization)\tLength of LCS is " << lcs_memo(X, Y, m, n, memo) << endl;
    cout << "(Tabulation)\tLength of LCS is " << lcs_tab(X, Y, m, n) << endl;
}