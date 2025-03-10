/*
Remove K Digits

বাং
Problem Statement
Given a non-negative integer 
N
N represented as a string, remove 
K
K digits from the number so that the new number is the smallest possible.

Input
First line of the input contains an integer 
T
T, number of test cases.
Next 
T
T lines contains a non-negative integer 
N
N and an integer 
K
K. 
N
N does not contain any leading zero.

Output
For each test case print the smallest possible integer after removing 
K
K digits from 
N
N. Output should not contain any leading zero.

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
∣
N
∣
∣N∣ 
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
∣
N
∣
∣N∣
Example 1:
Input:
2
1432219 3
10 1
Output:
1219
0
Example 2:
Input:
2
9999 4
123451 1
Output:
0
12341
*/


#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s; cin>>s;
    int k; cin>>k;
    stack<char>st;
    int count=0;
    for(int i=0;i<s.size();i++){
        while(!st.empty() && st.top()>(s[i]) && count<k){
            st.pop();
            count++;
        }
        st.push(s[i]);
    }
    while(count<k){
        st.pop();
        count++;
    }
    string res;
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    int idx=0;
    while(idx<s.size() && res[idx]=='0'){
        idx++;
    }
    
    res=res.substr(idx);
    if(res.empty()) res="0";
    cout<<res<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}