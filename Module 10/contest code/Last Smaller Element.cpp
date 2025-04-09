/*
Last Smaller Element

বাং
Problem Statement
Given an array of n numbers, sorted in non-decreasing order, and k queries. For each query, print the maximum number smaller than the given one. If there is no such number print -1.

Input
The first line of the input contains integers n and k, the length of the array and the number of queries. The second line contains n elements of the array, sorted in non-decreasing order. The third line contains k queries.

Output
For each of the k queries, print the the maximum number from the array smaller than the given one. If there are none, print -1.

Constraints
1 
≤
≤ 
N
,
k
N,k 
≤
≤ 
1
0
5
10 
5
 
Every integer of the array and queries is between 
−
1
0
9
−10 
9
  and 
1
0
9
10 
9
 
Example 1:
Input:
5 2
3 8 10 10 14
10
7
Output:
8
3
Example 2:
Input:
3 2
1 3 5
1
5
Output:
-1
3
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,k; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<k;i++){
        int num; cin>>num;
        
        auto good=[&](int mid){
            if(v[mid]<num) return true;
            else return false;
        };
        int low=0,high=n-1,idx=-1;
        while(high>=low){
            int mid=(high+low)/2;
            if(good(mid)) low=mid+1,idx=mid;
            else high=mid-1;
        }
        if(idx!=-1 && v[idx]<num) cout<<v[idx]<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}