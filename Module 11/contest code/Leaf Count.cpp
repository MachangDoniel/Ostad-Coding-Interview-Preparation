/*
You are given a tree with 
N
N nodes, you have to count the number of leaf nodes in the tree.

Input
The first line of input contains 
N
N. Then there are 
N
−
1
N−1 lines describing the edges. Each line contains two integers 
a
a and 
b
b. There is an edge between nodes 
a
a and 
b
b.

Output
Print the number of leaf nodes in the tree.

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
 
1
≤
a
,
b
≤
N
1≤a,b≤N
Example 1:
Input:
3
1 2
1 3
Output:
2
Example 2:
Input:
5
1 2
2 3
3 4
3 5
Output:
3
*/

#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(graph[i].size()==1) count++;
    }
    cout<<count<<endl;

    return 0;
}