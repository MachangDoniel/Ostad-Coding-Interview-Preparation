/*
Sliding Window Maximum

বাং
Problem Statement
Given an array on length 
N
N and an integer 
K
K, find the maximum for each and every contiguous subarray of size 
K
K.

Input
Input starts with an integer 
T
T, denoting the number of test cases.

Each case contains a line with two integers 
N
N and 
K
K denoting the array size and subarray size. The next line contains N space separated integers 
A
i
A 
i
​
  denoting the Array.

Output
For each test case, print 
N
−
K
+
1
N−K+1 integers denoting the maximum of each contiguous subarray of size 
K
K.

Constraints
1
1 
≤
≤ 
T
T 
≤
≤ 
100
100
1
1 
≤
≤ 
N
,
A
i
N,A 
i
​
  
≤
≤ 
10000
10000
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
Example 1:
Input:
1
9 3
1 2 3 1 4 5 2 3 6
Output:
3 3 4 5 5 5 6
Example 2:
Input:
3
4 4
1 1 4 5
10 5
7 4 6 3 10 3 2 2 1 4 
8 5
3 2 4 2 4 7 2 6 
Output:
5
10 10 10 10 10 4
4 7 7 7
*/


#include <bits/stdc++.h>
using namespace std;
     
void solve(){
    int n,k; cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>res;
    deque<int>dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(a[dq.front()]);
    for(int i=k;i<n;i++){
        while(!dq.empty() && i-k>=dq.front()){
            dq.pop_front();
        }
        while(!dq.empty() && a[i]>=a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(a[dq.front()]);
    }
    for(int ele:res){
        cout<<ele<<" ";
    }
    cout<<endl;

}

int main() {
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        solve();
    }
    return 0;
}