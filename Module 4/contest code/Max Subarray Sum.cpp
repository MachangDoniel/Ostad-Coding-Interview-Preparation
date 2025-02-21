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