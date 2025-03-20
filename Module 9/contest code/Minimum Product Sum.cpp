/*
Minimum Product Sum

বাং
Problem Statement
You are given an array of integers of size 
N
N. 
N
N is even. Initially, your score is 
0
0. You do the following operation until the array becomes empty.

For Each operation, select two integers from the array, remove them, multiply them, and add them to your score.
What is the minimum score you can achieve if you operate optimally?

Input
Input consists of two lines. First one having one integer 
N
N. Next line contains 
N
N integers.

Output
Print the minimum score you can achieve.

Constraints
2
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
 
N
N is even
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
6
10 8 14 3 10 2
Output:
138
Example 2:
Input:
4
1 3 2 3
Output:
9
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
     
int32_t main() {
    int n; cin>>n;
    multiset<int>ms;
    for(int i=0;i<n;i++){
        int ele; cin>>ele;
        ms.insert(ele);
    }
    int sum=0;
    while(ms.size()>1){
        int first=*ms.begin();
        ms.erase(ms.begin());
        int second=*ms.rbegin();
        auto it=ms.end();
        it--;
        ms.erase(it);
        int new_ele=first*second;
        sum+=new_ele;
    }
    cout<<sum<<endl;
    return 0;
}