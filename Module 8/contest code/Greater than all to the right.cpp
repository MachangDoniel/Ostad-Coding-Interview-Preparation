/*
Greater than all to the right

বাং
Problem Statement
Given an unsorted integer array, print all the elements that are greater than all elements present to their right. Print them in sorted order.

In other words, print those elements 
A
i
A 
i
​
  in the array 
A
A, such that for all 
j
j where 
j
>
i
j>i, 
A
j
A 
j
​
  
<
< 
A
i
A 
i
​
  holds.

Input
Input starts with an integer 
T
T, denoting the number of test cases.

Each case contains a line with an integer 
N
N denoting the number of element in the Array. The next line contains N space separated integers 
A
i
A 
i
​
  denoting the elements.

Output
For each test case print those elements that are greater than all elements present to their right. Print them in increasing order.

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
N 
≤
≤ 
10000
10000
1
1 
≤
≤ 
A
i
A 
i
​
  
≤
≤ 
10000
10000
Example 1:
Input:
2
5
1 2 3 4 5
5
5 4 3 2 1
Output:
5
1 2 3 4 5
Example 2:
Input:
2
5
10 4 6 3 5
7
5 1 1 1 2 4 1
Output:
5 6 10
1 4 5
*/


#include <bits/stdc++.h>
using namespace std;
     
void solve(){
    int n; cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++){
        int x; cin>>x; st.push(x);
    }
    int mx=0;
    while(!st.empty()){
        if(st.top()>mx){
            mx=st.top();
            cout<<st.top()<<" ";
        } 
        st.pop();
    }
    cout<<endl;
}

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}