// Problem 1: Digit DP – Count Beautiful Numbers
// Problem:
//  We define a "beautiful number" as a number where the sum of digits is divisible by k.
//  Given two numbers L and R, and a number k, count how many beautiful numbers exist between L and R (inclusive).
// Input:
//  Three integers: L, R, and k (1 ≤ L ≤ R ≤ 10¹⁸, 1 ≤ k ≤ 100)
// Output:
//  Print the count of beautiful numbers between L and R.
// Example:
// Input: 1 20 5
// Output: 4
// Hint: Use Digit DP with memoization: dp[pos][sum][tight]


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int k;
string s;
int dp[20][100][2];

int dfs(int pos, int sum, bool tight) {
    if (pos == s.size()) return sum % k == 0;

    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    int limit = tight ? s[pos] - '0' : 9;
    int res = 0;

    for (int d = 0; d <= limit; ++d) {
        res += dfs(pos + 1, (sum + d) % k, tight && (d == limit));
    }

    return dp[pos][sum][tight] = res;
}

int count_beautiful(long long num) {
    s = to_string(num);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, true);
}

int main() {
    long long L, R;
    cin >> L >> R >> k;
    cout << (count_beautiful(R) - count_beautiful(L - 1)) << endl;

    return 0;
}
