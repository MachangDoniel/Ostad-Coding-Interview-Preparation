/*
First Unique Character

বাং
Problem Statement
Given a string 
S
S, find the first non-repeating character in it and print it. If it does not exist, print 'N'.

Input
First line of the input contains an integer 
T
T, number of test cases.
Next 
T
T lines contains a string 
S
S.

Output
For each test case print the first character in the string that is not found twice. If such character doesn't exist print 'N'.

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
S
∣
∣S∣ 
≤
≤ 
10000
10000
S
S consists of lower case english letters only [a-z]
Example 1:
Input:
5
abcdef
abcdac
abcdcba
abccba
zxywyz
Output:
a
b
d
N
x
Example 2:
Input:
5
ostad
coding
interview
lollipop
deed
Output:
o
c
n
i
N
*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin>>s;
    map<char,int>mp;
    queue<char>q;
    for(int i=0;i<s.size();i++){
        q.push(s[i]);
        mp[s[i]]++;
    }
    while(!q.empty()){
        if(mp[q.front()]==1){
            cout<<q.front()<<endl;
            return;
        }
        q.pop();
    }
    cout<<"N"<<endl;
}
     
int main() {
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        solve();
    }

    return 0;
}