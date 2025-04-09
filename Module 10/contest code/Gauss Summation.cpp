/*
Gauss Summation

বাং
Problem Statement
Given an integer 
N
N. You to find the minimum integer 
X
X such that 
∑
i
=
1
X
i
≥
N
∑ 
i=1
X
​
 i≥N.

Sum of 
1
1 to 
X
X is greater or equal than 
N
N.
Input
The first line of the input contains integer 
N
N.

Output
Print the minimum integer 
X
X.

Constraints
1
1 
≤
≤ 
N
N 
≤
≤ 
10
10
18
18
Example 1:
Input:
6
Output:
3
Example 2:
Input:
16
Output:
6
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int mid,int n){
    int sum=mid*(mid+1)/2;
    return sum>=n;
}

int32_t main() {
    int n; cin>>n;
    int low=-1,high=1.5*1e9;
    while(high>low+1){
        int mid=(high+low)/2;
        if(good(mid,n)) high=mid;
        else low=mid;
    }
    cout<<high<<endl;
    return 0;
}