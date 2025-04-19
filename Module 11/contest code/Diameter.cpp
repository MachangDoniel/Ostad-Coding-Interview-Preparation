/*
Diameter

বাং
Problem Statement
You are given a tree with 
N
N nodes, you have to find the diameter of the tree.

Diameter of a tree is the maximum distance between two nodes.
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
Print the diameter of the tree.

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

vector<vector<int>>graph;
vector<bool>vis;

pair<int,int> applyBfs(int parent){
    queue<pair<int,int>>q;
    q.push({parent,0});
    int highestDistNode,maxDist;
    while(!q.empty()){
        int parent=q.front().first;
        int dist=q.front().second;
        vis[parent]=true;
        highestDistNode=parent;
        maxDist=dist;
        q.pop();
        for(int child:graph[parent]){
            if(!vis[child]) q.push({child,dist+1});
        }
    }
    return {highestDistNode,maxDist};
}
     
int main() {
    int n; cin>>n;
    graph.resize(n+1);
    vis.resize(n+1,false);
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    pair<int,int>pp=applyBfs(1);  // return highestDistanceNodeFromNode1, highestDistanceFromNode1
    vis.clear();
    vis.resize(n+1,false);
    pair<int,int>pp2=applyBfs(pp.first);
    cout<<pp2.second<<endl;

    return 0;
}