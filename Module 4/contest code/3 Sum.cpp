// 3 Sum

// Problem Statement
// You are given an array A of unique integers of size N. Your task is to count the number of index triplets i, j, k such that 1 ≤ i < j < k ≤ N and A[i] + A[j] + A[k] = 0.

// Input
// The input consists of two lines:

// The first line contains an integer N — the number of elements in the array.

// The second line contains N space-separated unique integers, each between −10⁹ and 10⁹.

// Output
// Print a single integer — the number of triplets (i, j, k) that satisfy the condition A[i] + A[j] + A[k] = 0.

// Constraints

// 1 ≤ N ≤ 10³

// All elements of the array are unique and in the range [−10⁹, 10⁹]

// Example

// Input  1
// 6  
// 1 -2 3 -4 5 6  

// Output  1
// 2  

// Input  2
// 3  
// 1 2 5  

// Output  2
// 0  
// Notes
// In the first example, the valid triplets are:

// 1 + 3 + (−4) = 0

// −2 + (−4) + 6 = 0

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