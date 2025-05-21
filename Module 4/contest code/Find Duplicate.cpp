// Find Duplicate

// Problem Statement
// You are given an array of integers where all the elements are different except one element which appears twice. Your task is to find that duplicate element.

// Input
// The input consists of two lines:

// The first line contains an integer N — the size of the array.

// The second line contains N space-separated integers between 1 and N.

// Output
// Print the integer that occurs twice in the array.

// Constraints

// 2 ≤ N ≤ 5000

// Every integer in the array is between 1 and N

// Example

// Input  1
// 4  
// 1 2 3 2  

// Output  1
// 2  

// Input  2
// 6  
// 1 2 5 4 3 5  

// Output  2
// 5  
// Notes
// In the first example, the number 2 occurs twice, so the answer is 2.


#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_set<int> seen;
    int num;
    
    for (int i = 0; i < N; i++) {
        cin >> num;
        // If num is already in the set, it's the duplicate
        if (seen.find(num) != seen.end()) {
            cout << num << endl;
            return 0; // We found the duplicate, no need to continue
        }
        // Otherwise, add it to the set
        seen.insert(num);
    }
    
    return 0;
}
