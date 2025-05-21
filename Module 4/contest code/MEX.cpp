// MEX

// Problem Statement
// You are given an array A of non-negative integers of size N. Your task is to find the minimum non-negative integer (called the MEX) which is not present in the array.

// Input
// The input consists of two lines:

// The first line contains an integer N — the size of the array.

// The second line contains N space-separated integers between 0 and 10⁹.

// Output
// Print the minimum non-negative integer which is not present in the array.

// Constraints

// 1 ≤ N ≤ 10⁵

// Each integer in the array is between 0 and 10⁹

// Example

// Input  1
// 6  
// 1 2 0 4 4 6  

// Output  1
// 3  

// Input  2
// 3  
// 1 2 3  

// Output  2
// 0  
// Notes
// In the first example, 3 is the smallest non-negative integer not found in the array [1, 2, 0, 4, 4, 6].
// In the second example, 0 is not present in the array [1, 2, 3], so the answer is 0.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> numSet;
    int num;

    // Read input numbers and insert into a set
    for (int i = 0; i < N; i++) {
        cin >> num;
        numSet.insert(num);
    }

    // Find the smallest missing integer
    int missing = 0;
    while (numSet.count(missing)) {
        missing++;
    }

    cout << missing << endl;
    return 0;
}
