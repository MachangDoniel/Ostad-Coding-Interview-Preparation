#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string num;
int K, D;
ll dp[20][510][2][2]; // pos, digit sum, count of D mod 2, tight

ll recur(int pos, int sum, int cntDmod2, bool tight) {
    if (sum > K) return 0;
    if (pos == num.size()) {
        return (sum == K && cntDmod2 == 0); // digit D occurs even times
    }
    
    if (dp[pos][sum][cntDmod2][tight] != -1) return dp[pos][sum][cntDmod2][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    ll res = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        int newCnt = cntDmod2;
        if (digit == D) newCnt ^= 1;
        res += recur(pos + 1, sum + digit, newCnt, tight && (digit == limit));
    }

    return dp[pos][sum][cntDmod2][tight] = res;
}

ll solve(ll val) {
    num = to_string(val);
    memset(dp, -1, sizeof(dp));
    return recur(0, 0, 0, 1);
}

int main() {
    ll L, R;
    cin >> L >> R >> K >> D;
    if (L > R) swap(L, R);
    cout << solve(R) - solve(L - 1) << "\n";
    return 0;
}