// Max Subarray Sum

// Problem Statement
// You are given an array of integers. Your task is to find the maximum subarray sum — that is, the largest possible sum of a contiguous subarray.

// Input
// The input consists of two lines:

// The first line contains an integer N — the number of elements in the array.

// The second line contains N space-separated integers, each between −10⁹ and 10⁹.

// Output
// Print a single integer — the maximum subarray sum.

// Constraints

// 1 ≤ N ≤ 10⁵

// Each integer in the array is between −10⁹ and 10⁹

// Example


// Input  1
// 3  
// 2 -1 3  

// Output  1
// 4  

// Input  2
// 5  
// -1 -2 -3 -4 -5  

// Output  2
// -1  
// Notes
// In the first example, the subarray [2, -1, 3] has the maximum sum of 4.
// In the second example, all numbers are negative, and the maximum subarray is [-1], which gives a sum of -1.


#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 

// #define int long long

int maxSubarraySum(vector<int>& arr, int N) 
{ 
    long long maxSum = INT_MIN, currentSum = 0; 
    for (int i = 0; i < N; i++) { 
            currentSum += arr[i]; 
            maxSum = max(maxSum, currentSum); 
            if (currentSum < 0) {
                 currentSum = 0; 
            } 
            
        } 
        return maxSum; 
    } 
    
main() 
{ 
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++){ 
        cin >> arr[i]; 
    } 
    cout << maxSubarraySum(arr, N) << endl; 
}