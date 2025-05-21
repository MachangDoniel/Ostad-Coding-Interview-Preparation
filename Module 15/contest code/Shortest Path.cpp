#include <bits/stdc++.h>
using namespace std;

int n,m,count;
vector<vector<int>>adj;
vector<int>dist;

// follows bfs
void bfs(int node){
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(int child : adj[parent]){
            if(dist[child]==-1){
                dist[child]=dist[parent]+1;
                q.push(child);
            }
        }
    }
}
     
int main() {
    cin>>n>>m;
    adj.resize(n+1);
    dist.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dist[1]=1;
    bfs(1);
    dist[n]==-1?cout<<"IMPOSSIBLE":cout<<dist[n];
    cout<<endl;

    return 0;
}