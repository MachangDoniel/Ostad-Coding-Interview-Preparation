/*
Find The Position

বাং
Problem Statement
You are given an sorted array of integers of size 
N
N and an integer 
X
X and 
Q
Q queries. In each query you will be given an integer 
X
X, you have to find the first position of 
X
X in the array. If 
X
X is not present then print 
−
1
−1.

Input
The input consists of three lines. First one having two integers 
N
N and 
Q
Q. Next line contains 
N
N integers. The third line will have 
Q
Q integers of each query.

Output
Print 
Q
Q lines, in each line print the first position of the desired integer. If the integer is not present in the array print -1.

Constraints
1 
≤
≤ 
N
,
Q
N,Q 
≤
≤ 
1
0
5
10 
5
 
−
1
0
9
−10 
9
  
≤
≤ 
X
X 
≤
≤ 
1
0
9
10 
9
 
Every integer of the array is between 
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
10 7
Output:
3
-1
Example 2:
Input:
3 2
1 3 5
1 5
Output:
1
3
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,q; cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<q;i++){
        int num; cin>>num;
        
        auto good=[&](int mid){
            if(num<=v[mid]) return true;
            else return false;
        };
        int low=0,high=n-1,idx=-1;
        while(high>=low){
            int mid=(high+low)/2;
            if(good(mid)) high=mid-1,idx=mid;
            else low=mid+1;
        }
        if(idx!=-1 && v[idx]==num) cout<<idx+1<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}