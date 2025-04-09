/*
Perfect Square

বাং
Problem Statement
Given an Integer 
N
N. You have to tell if it is a perfect square number or not.

Input
The first line of the input contains integer 
N
N.

Output
Print YES if it is a perfect square number else print NO.

Constraints
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
49
Output:
YES
Example 2:
Input:
24
Output:
NO
*/

// Runtime 3.9 ms
#include <bits/stdc++.h>
using namespace std;

#define int long long
     
int32_t main() {
    int n; cin>>n;
    int sq=sqrt(n);
    if(sq*sq==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

// Runtime: 4.05 ms
#include <bits/stdc++.h>
using namespace std;

#define int long long
     
int32_t main() {
    int n; cin>>n;
    int low=-1,high=1.5*1e9;
    while(high>low+1){
        int mid=(high+low)/2;
        if(mid*mid<=n) low=mid;
        else high=mid;
    }
    if(low*low==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}