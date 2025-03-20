/*
Sort By Frequency

বাং
Problem Statement
You are given an array of integers of size 
N
N. You have to sort the array by the frequency of the elements.

The more frequent element will place before the less frequent one.
If two or more elements have the same frequency the smller element will place before larger ones.
Input
Input consists of two lines. First one having one integer 
N
N. Next line contains 
N
N integers.

Output
Print the array after sorting.

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
5
10 8 14 3 10
Output:
10 3 8 14
Example 2:
Input:
3
1 2 2
Output:
2 1
Note:
In example 1, frequency of 10 is 2 and the other elements have frequency 1. So, 10 placed first, 8,14,3 have the same frequency but 3 is smaller among them so 3 places before 8 and 8 places before 14.
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<pair<int,int>>res;
    for(auto it:mp){
        res.push_back({-it.second,it.first});
    }
    sort(res.begin(),res.end());
    for(auto it:res){
        cout<<it.second<<" ";
    }
    cout<<endl;


    return 0;
}