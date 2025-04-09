/*
Count The Pairs

বাং
Problem Statement
Given an array 
A
A of integers of size 
N
N and an integer 
X
X. How many pairs 
(
i
<
j
)
(i<j) such that 
A
i
∗
A
j
≤
X
A 
i
​
 ∗A 
j
​
 ≤X.

Input
The first line of the input contains integers 
N
N and 
X
X. The next line contains 
N
N integers.

Output
Print the number of pairs 
(
i
<
j
)
(i<j) such that 
A
i
∗
A
j
≤
X
A 
i
​
 ∗A 
j
​
 ≤X.

Constraints
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
≤
≤ 
X
X 
≤
≤ 
10
10
10
10
Every integer of the array 
1
1 and 
1
0
5
10 
5
 
Example 1:
Input:
5 6
1 2 3 4 5
Output:
5
Example 2:
Input:
3 1
2 5 3
Output:
0
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,x; cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=0;i<n;i++){
        int low=0,high=n-1,idx=-1;
        auto good=[&](int mid){
            return a[i]*a[mid]<=x;
        };
        while(high>=low){
            int mid=(high+low)/2;
            if(good(mid)) low=mid+1,idx=mid;
            else high=mid-1;
        }
        if(i<idx) sum+=(idx-i);
    }
    cout<<sum<<endl;

    return 0;
}