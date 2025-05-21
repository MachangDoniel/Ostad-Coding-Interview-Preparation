// Remove Duplicate

// Problem Statement
// You are given a sorted array of integers in non-decreasing order. Your task is to remove the duplicate integers and print the resulting array in sorted order.

// Input
// The input consists of two lines:

// The first line contains an integer N — the size of the array.

// The second line contains N space-separated integers between 1 and N.

// Output
// Print the array after removing duplicates, in sorted order.

// Constraints

// 2 ≤ N ≤ 10⁵

// Every integer in the array is between 1 and N.

// Example

// Input  1
// 4  
// 1 3 3 4  

// Output  1
// 1 3 4  

// Input  2
// 6  
// 1 2 3 4 5 6  

// Output  2
// 1 2 3 4 5 6  



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Remove duplicates using a loop (since the array is sorted)
    vector<int> uniqueArr;
    uniqueArr.push_back(arr[0]); // First element is always unique

    for (int i = 1; i < N; i++) {
        if (arr[i] != arr[i - 1]) { // Compare with the previous element
            uniqueArr.push_back(arr[i]);
        }
    }

    // Print the unique elements
    for (int num : uniqueArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
