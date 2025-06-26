#include <bits/stdc++.h>
using namespace std;

int dp[20][200][2]; // pos, sum, tight

// Count numbers with digit sum `sum`, starting at pos `pos`, tight constraint
int countDigitSum(string &s, int pos, int sum, bool tight) {
    if (sum < 0) return 0;
    if (pos == s.size()) return sum == 0;

    if (dp[pos][sum][tight] != -1)
        return dp[pos][sum][tight];

    int res = 0;
    int limit = tight ? s[pos] - '0' : 9;

    for (int d = 0; d <= limit; ++d) {
        res += countDigitSum(s, pos + 1, sum - d, tight && (d == limit));
    }

    return dp[pos][sum][tight] = res;
}

int countUpto(long long x) {
    string s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return countDigitSum(s, 0, 10, 1);
}

int main() {
    int K;
    cin >> K;

    long long low = 1, high = 1e15, ans = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (countUpto(mid) >= K) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}