// Climbing Ways

// You are climbing a staircase. It takes n steps to reach the top. Each time you can climb 1 or 2 steps.

// Your task is to count how many distinct ways you can reach the top.
// Input

// A single integer n (1 ≤ n ≤ 10⁵)
// Output

// Print the number of distinct ways modulo 10⁹ + 7
// Sample Input

// 5
// Sample Output

// 8
// Explanation

// You can climb in these ways:
// 1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1
// Total: 8 ways.


#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // 1 way to stay at ground
    dp[1] = 1;  // 1 way to climb 1 step

    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n] << endl;
    return 0;
}
