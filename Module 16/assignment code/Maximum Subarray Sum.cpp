// Given an array of n integers, find the maximum sum of a contiguous subarray.
// Input

// First line: integer n (1 ≤ n ≤ 10⁵)
// Second line: n integers a₁, a₂, ..., aₙ where -10⁴ ≤ aᵢ ≤ 10⁴
// Output

// Maximum subarray sum
// Sample Input

// 5
// -2 1 -3 4 5
// Sample Output

// 9
// Explanation

// The subarray [4, 5] has the maximum sum of 9.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int max_sum = a[0];
    int current_sum = a[0];

    for (int i = 1; i < n; ++i) {
        current_sum = max(a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    return 0;
}
