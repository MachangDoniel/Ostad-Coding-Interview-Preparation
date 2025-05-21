#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>dis;

void bfs(int root){
    queue<int>q;
    q.push(root);
    dis[root]=0;
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(int child : adj[parent]){
            if(dis[child]==-1){
                dis[child]=dis[parent]+1;
                q.push(child);
            }
        }
    }
}
     
int main() {
    int n,m,k; cin>>n>>m>>k;
    adj.resize(n+1);
    dis.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(dis[i]!=-1) dis[i]*=k;
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}