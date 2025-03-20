/*
Kth Number

বাং
Problem Statement
You are given an array of integers of size 
N
N. You have to find the 
K
t
h
Kth smallest number in the array.

Input
Input consists of two lines. First one having two integers 
N
N and 
K
K. Next line contains 
N
N integers.

Output
Print the 
k
t
h
kth smallest number.

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
10
Example 2:
Input:
3 1
1 2 2
Output:
1
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<a[k-1]<<endl;
    return 0;
}