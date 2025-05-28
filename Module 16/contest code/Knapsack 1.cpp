// Knapsack 1
// 📝 Problem Statement
// You are given N items. Each item has a weight and a value. You are also given a maximum weight capacity W. Your task is to choose a subset of the items such that:

// The total weight of the chosen items does not exceed W.

// The total value of the chosen items is maximized.

// 📥 Input
// The first line contains two integers:
// N — the number of items
// W — the maximum weight capacity of the knapsack

// The next N lines each contain two integers:
// wᵢ — weight of the i-th item
// vᵢ — value of the i-th item

// 📤 Output
// Print a single integer — the maximum total value achievable without exceeding the weight limit W.

// 🔒 Constraints
// 1 ≤ N ≤ 100

// 1 ≤ W ≤ 10⁵

// 1 ≤ wᵢ ≤ W

// 1 ≤ vᵢ ≤ 10⁹

// 💡 Example 1
// Input:

// Copy
// Edit
// 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2
// Output:

// Copy
// Edit
// 17
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
// Explanation:
// In Example 2, the 2nd and 3rd items are selected.
// Their total weight is 5 + 4 = 9 ≤ W = 9
// Their total value is 8 + 8 = 16, which is the maximum possible.


#include <iostream>
#include <vector>
using namespace std;

#define int long long

int32_t main() {
    int n,w; cin>>n>>w;

    vector<int>weight(n),value(n);
    for(int i=0;i<n;i++) {
        cin>>weight[i]>>value[i];
    }

    vector<int> dp(w+1,0);

    for(int i=0;i<n;i++) {
        for(int j=w;j>=weight[i];j--) {
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[w]<<endl;
    return 0;
}