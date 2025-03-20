/*
Maximum Sum

বাং
Problem Statement
You are given an array of integers of size 
N
N. You can select 
K
K numbers from the array. What is the maximum sum you can achieve?

Input
Input consists of two lines. First one having two integers 
N
N and 
K
K. Next line contains 
N
N integers.

Output
Print the maximum sum you can achieve.

Constraints
1
1 
≤
≤ 
N
N 
≤
≤ 
1
0
5
10 
5
 
1
1 
≤
≤ 
K
K 
≤
≤ 
N
N
Every integer of the array is between 
1
1 and 
1
0
9
10 
9
 
Example 1:
Input:
5 3
10 8 14 3 10
Output:
34
Example 2:
Input:
3 1
1 2 2
Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
     
int32_t main() {
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=0,idx=n-1;i<k;i++,idx--){
        sum+=a[idx];
    }
    cout<<sum<<endl;
    return 0;
}