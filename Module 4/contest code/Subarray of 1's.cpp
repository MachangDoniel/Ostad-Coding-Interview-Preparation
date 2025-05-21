// Subarray of 1's

// Problem Statement
// You are given an array consisting of 0's and 1's. Your task is to find the maximum length of a subarray where all elements are 1.

// Input
// The input consists of two lines:

// The first line contains an integer N — the size of the array.

// The second line contains N space-separated integers, each either 0 or 1.

// Output
// Print a single integer — the maximum length of a subarray consisting only of 1's.

// Constraints

// 1 ≤ N ≤ 5000

// Each element of the array is either 0 or 1

// Example

// Input  1
// 6  
// 0 1 0 1 1 0  

// Output  1
// 2  

// Input  2
// 3  
// 0 0 0  

// Output  2
// 0  
// Notes
// In the first example, the longest subarray with all 1's is [1, 1] of length 2, so the output is 2.
// In the second example, there are no 1's, so the output is 0.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_max_length_subarray(int N, vector<int>& arr) {
    int max_length = 0;
    int current_length = 0;
    
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            current_length++;
            max_length = max(max_length, current_length);
        } else {
            current_length = 0;
        }
    }
    
    return max_length;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << find_max_length_subarray(N, arr) << endl;
    
    return 0;
}
