// Knapsack 2
// 📝 Problem Statement
// You are given N items, each with a weight and a value, and a maximum weight limit W.
// Your task is to select a subset of items such that:

// The total weight of the selected items does not exceed W.

// The sum of the values of the selected items is maximized.

// 📥 Input Format
// First line contains two integers:
// N — number of items
// W — maximum weight capacity of the knapsack

// Next N lines: each line contains two integers wᵢ and vᵢ — the weight and value of the i-th item.

// 📤 Output Format
// Print a single integer: the maximum total value achievable without exceeding weight W.

// 🔒 Constraints
// 1 ≤ N ≤ 100

// 1 ≤ W ≤ 10⁹

// 1 ≤ wᵢ ≤ W

// 1 ≤ vᵢ ≤ 10³

// 💡 Example 1
// Input:

// Copy
// Edit
// 1 1000000000
// 1000000000 10
// Output:

// Copy
// Edit
// 10
// 💡 Example 2
// Input:

// Copy
// Edit
// 3 9
// 6 15
// 5 8
// 4 8
// Output:

// Copy
// Edit
// 16
// Explanation: Items 2 and 3 are selected.
// Their total weight = 5 + 4 = 9 ≤ 9
// Their total value = 8 + 8 = 16

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    long long W;
    cin >> n >> W;

    vector<int> weights(n), values(n);
    int sum_values = 0;

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
        sum_values += values[i];
    }

    // dp[v] = minimum weight needed to get value v
    vector<long long> dp(sum_values + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int v = sum_values; v >= values[i]; --v) {
            if (dp[v - values[i]] != LLONG_MAX) {
                dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
            }
        }
    }

    // Find the maximum value that can be achieved with weight <= W
    int result = 0;
    for (int v = 0; v <= sum_values; ++v) {
        if (dp[v] <= W) {
            result = v;
        }
    }

    cout << result << endl;
    return 0;
}
