// Pair Sum

// Problem Statement
// You are given an array A of non-negative integers of size N and an integer S. You need to determine whether there exist two indices i and j (1 ≤ i < j ≤ N) such that A[i] + A[j] = S.

// Input
// The input consists of two lines:

// The first line contains two integers N and S.

// The second line contains N space-separated integers between 0 and 10⁶.

// Output
// Print Yes if such indices exist, otherwise print No.

// Constraints

// 2 ≤ N ≤ 10⁵

// 0 ≤ S ≤ 2 * 10⁶

// Every integer in the array is between 0 and 10⁶

// Example

// Input  1
// 6 4  
// 1 2 3 4 5 6  

// Output  1
// Yes  

// Input  2
// 3 5  
// 1 2 5  

// Output  2
// No  
// Notes
// In the first example, the pair (1, 3) (values 1 and 3) sums to 4, so the output is Yes.
// In the second example, no pair sums to 5, so the output is No.



#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;

    int num;
    unordered_set<int> seen;

    for (int i = 0; i < N; i++) {
        cin >> num;

        // Check if the complement exists in the set
        if (seen.find(S - num) != seen.end()) {
            cout << "Yes" << endl;
            return 0;
        }

        // Add the current number to the set
        seen.insert(num);
    }

    // If no pair is found
    cout << "No" << endl;
    return 0;
}
