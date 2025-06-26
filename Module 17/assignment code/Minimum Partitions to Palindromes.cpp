// Problem 2: Minimum Partitions to Palindromes
// Problem:
//  Given a string s, you are allowed to partition it into one or more palindromic substrings.
//  Find the minimum number of cuts needed to make all substrings palindromes.
// Input:
//  A single string s (1 ≤ |s| ≤ 1000)
// Output:
//  An integer denoting the minimum number of cuts.
// Example:
//  Input: aab
//  Output: 1
//  Explanation: "aa" | "b" is a valid partition with 1 cut.
// Hint: Use dp[i] = min(dp[j] + 1) where s[j+1...i] is palindrome.

#include <bits/stdc++.h>
using namespace std;

int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // Precompute palindrome substrings
    for (int i = 0; i < n; ++i)
        isPal[i][i] = true;

    for (int i = 0; i < n - 1; ++i)
        isPal[i][i + 1] = (s[i] == s[i + 1]);

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
        }
    }

    // DP for minimum cuts
    vector<int> dp(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        if (isPal[0][i]) {
            dp[i] = 0;
        } else {
            for (int j = 0; j < i; ++j) {
                if (isPal[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1];
}

int main() {
    string s;
    cin >> s;
    cout << minCut(s) << endl;
    return 0;
}
