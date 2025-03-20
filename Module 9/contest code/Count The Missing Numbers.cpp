/*
Count The Missing Numbers

বাং
Problem Statement
You are given an array of integers of size 
N
N and an integer 
K
K. Count the number of integers smaller than 
K
K which are missing in the array.

Input
Input consists of two lines. First one having two integers 
N
N and 
K
K. Next line contains 
N
N integers.

Output
Print the number of integers smaller than 
K
K which are missing in the array.

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
1
0
9
10 
9
 
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
5 9
10 8 14 3 10
Output:
6
Example 2:
Input:
3 1
1 2 2
Output:
0
Notes:
In example 1,
1
,
2
,
4
,
5
,
6
,
7
1,2,4,5,6,7 are missing in the array and smaller than 
9
9.
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
    int ans=0,prevUnUsed=1;
    for(int i=0;i<n;i++){
        // cout<<a[i]<<" ";
        if(a[i]<k){
            ans+=max(0,(a[i]-prevUnUsed));
            prevUnUsed=a[i]+1;
        }
        else break;
    }
    ans+=max(0,k-prevUnUsed);
    // cout<<endl;
    cout<<ans<<endl;

    return 0;
}