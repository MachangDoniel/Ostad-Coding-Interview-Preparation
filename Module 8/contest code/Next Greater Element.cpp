/*
Next Greater Element

বাং
Problem Statement
Given an integer array, find the next greater element for every array element. The next greater element of a number 
x
x is the first greater number to the right of 
x
x in the array.

In other words, for each element 
A
i
A 
i
​
  in the array 
A
A, find an element 
A
j
A 
j
​
  such that 
j
>
i
j>i and 
A
j
A 
j
​
  
>
> 
A
i
A 
i
​
  and the value of 
j
j should be as minimum as possible. If the next greater element doesn’t exist in the array for any element, consider it -1.

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
For each test case print 
N
N integers the next greater element. If such element doesn't exist print -1.

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
7
2 7 3 5 4 6 8
5
1 2 3 4 5
Output:
7 8 5 6 6 8 -1
2 3 4 5 -1
Example 2:
Input:
1
5
5 4 3 2 1
Output:
-1 -1 -1 -1 -1
*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>res(n,-1);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=a[i]){
            st.pop();
        }
        if(!st.empty()){
            res[i]=st.top();
        }
        st.push(a[i]);
    }
    for(int ele:res){
        cout<<ele<<" ";
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