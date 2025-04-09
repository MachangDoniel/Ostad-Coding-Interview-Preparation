/*
Kth Smallest Number

বাং
Problem Statement
Given an array 
A
A of integers of size 
N
N and an integer 
K
K. If we calculate all pair product 
A
i
∗
A
j
A 
i
​
 ∗A 
j
​
  such that 
(
i
<
j
)
(i<j). And sort them then what will be the 
K
t
h
Kth number?

Input
The first line of the input contains integers 
N
N and 
K
K. The next line contains 
N
N integers.

Output
Print the 
K
t
h
Kth number.

Constraints
2 
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
K
K 
≤
≤ 
(
N
∗
(
N
−
1
)
)
/
2
(N∗(N−1))/2
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
8
Example 2:
Input:
3 2
2 5 3
Output:
10
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

// countLessOrEqual
int good(vector<int>&a,int mid) {
    int n=a.size(),count=0;
    for(int i=0,j=n-1;i<j;i++) {
        while(j>i && a[i]*a[j]>mid) j--;
        count+=(j-i);
    }
    return count;
}

int32_t main() {
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    sort(a.begin(),a.end());
    if(1<=k && 2*k<=n*(n-1)){
        int low=a[0]*a[1],high=a[a.size()-1]*a[a.size()-2];
        int ans=high;
        while(high>=low) {
            int mid=low+(high-low)/2;
            if(good(a,mid)>=k) high=mid-1,ans=mid;
            else low=mid+1;
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
        return 0;
    }

    return 0;
}

