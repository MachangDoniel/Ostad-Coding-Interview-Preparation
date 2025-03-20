/*
Find The Median

বাং
Problem Statement
You are given an array of integers of size 
N
N. 
N
N is odd. You have to find the median of the array.

Note: The median of array is the middle element of a sorted array in case of odd number of elements in an array.

Input
Input consists of two lines. First one having one integer 
N
N. Next line contains 
N
N integers.

Output
Print the median.

Constraints
1
1 
≤
≤ 
N
N 
<
< 
1
0
5
10 
5
 
N
N is odd
Every integer of the array is between 
1
1 and 
1
0
6
10 
6
 
Example 1:
Input:
5
10 8 14 3 10
Output:
10
Example 2:
Input:
3
1 4 2
Output:
2 
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<a[n/2]<<endl;
    return 0;
}