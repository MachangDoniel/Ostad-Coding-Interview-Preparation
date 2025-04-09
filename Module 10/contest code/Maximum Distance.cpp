/*
Maximum Distance

বাং
Problem Statement
Given 
N
N 2D points you have to find out the maximum Euclidean distance between two different points.

Input
The first line of the input contains integer 
N
N. Then 
N
N points are given.

Output
Print the square of the maximum distance.

Constraints
2 
≤
≤ 
N
N 
≤
≤ 
1
0
3
10 
3
 
Every point's 
x
x and 
y
y cordinates are integers and between 
−
1
0
5
−10 
5
  and 
1
0
5
10 
5
 .
Example 1:
Input:
3
1 2
3 4
10 10
Output:
145
Example 2:
Input:
2
1 1
1 1
Output:
0
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int mxDiff=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff=(v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
            mxDiff=max(mxDiff,diff);
        }
    }
    cout<<mxDiff<<endl;
    return 0;
}