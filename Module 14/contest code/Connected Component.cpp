#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<bool>vis;

void dfs(int node){
    vis[node]=true;
    for(int child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
     
int main() {
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,false);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            count++;
            dfs(i);
        }
    }
    cout<<count<<endl;

    return 0;
}