#include <bits/stdc++.h>
using namespace std;

string num;
int K;
long long dp[20][500 + 5][2]; // max 18 digits, max sum ~162, tight=0/1

// Digit DP function
long long count(int pos, int sum, bool tight) {
    if (sum > K) return 0; // Prune unnecessary paths
    if (pos == num.size()) return sum == K;

    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    long long res = 0;

    for (int digit = 0; digit <= limit; digit++) {
        bool newTight = (tight && digit == limit);
        res += count(pos + 1, sum + digit, newTight);
    }

    return dp[pos][sum][tight] = res;
}

// Helper function to count numbers <= val with digit sum = K
long long solve(long long val) {
    num = to_string(val);
    memset(dp, -1, sizeof(dp));
    return count(0, 0, 1);
}

int main() {
    long long L, R;
    cin >> L >> R >> K;

    if (L > R) swap(L, R);

    long long ans = solve(R) - solve(L - 1);
    cout << ans << "\n";
    return 0;
}