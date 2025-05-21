// Rotate The Array

// Problem Statement
// You are given an array of integers and an integer K.

// If K = 0, rotate the array right by one position.

// If K = 1, rotate the array left by one position.

// Input
// The input consists of two lines:

// The first line contains two integers N and K.

// The second line contains N space-separated integers between 1 and N.

// Output
// Print the array after the specified rotation.

// Constraints

// 1 ≤ N ≤ 5000

// 0 ≤ K ≤ 1

// Every integer in the array is between 1 and N.

// Example

// Input  1
// 4 0  
// 1 2 3 4  

// Output  1
// 4 1 2 3  

// Input  2
// 6 1  
// 1 2 5 4 3 5  

// Output  2
// 2 5 4 3 5 1  
// Notes
// In the first example, K = 0, so rotate right by one: (1, 2, 3, 4) becomes (4, 1, 2, 3).




#include <iostream>
#include <vector>
using namespace std;

void rotate_array(int N, int K, vector<int>& arr) {
    if (K == 0) {
        // Rotate right by one position
        int last = arr[N - 1];
        for (int i = N - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    } else if (K == 1) {
        // Rotate left by one position
        int first = arr[0];
        for (int i = 0; i < N - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[N - 1] = first;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    rotate_array(N, K, arr);
    
    // Output the rotated array
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
