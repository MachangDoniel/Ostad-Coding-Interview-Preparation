// Max Unsorted Subarray

// Problem Statement
// You are given an array of integers. Your task is to find the maximum subarray such that sorting this subarray will make the entire array sorted.

// Input
// The input consists of two lines:

// The first line contains an integer N — the size of the array.

// The second line contains N space-separated integers, each between −10⁹ and 10⁹.

// Output
// Print two integers: the starting and ending indices (0-based) of the subarray.
// If the array is already sorted and no such subarray is needed, print -1.

// Constraints

// 2 ≤ N ≤ 10⁵

// Each integer in the array is between −10⁹ and 10⁹

// Example

// Input  1
// 3  
// 2 -1 3  

// Output  1
// 1 2  

// Input  2
// 5  
// 1 2 3 3 5  

// Output  2
// -1  
// Notes
// In the first example, sorting the subarray [2, -1] (i.e., from index 0 to 1) results in the full array being sorted.
// In the second example, the array is already sorted, so no subarray needs to be sorted.

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>preMax(n),sufMin(n);
    preMax[0]=v[0];
    for(int i=1;i<n;i++){
        preMax[i]=max(preMax[i-1],v[i]);
    }
    sufMin[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        sufMin[i]=min(sufMin[i+1],v[i]);
    }
    int l=-1,r=-1;
    for(int i=0;i<n;i++){
        if(sufMin[i]!=preMax[i]){
            if(l==-1) l=i+1;
            else r=i+1;
        }
        // cout<<preMax[i]<<" "<<sufMin[i]<<endl;
    }
    if(l==-1) cout<<-1<<endl;
    else cout<<l<<" "<<r<<endl;
    return 0;
}