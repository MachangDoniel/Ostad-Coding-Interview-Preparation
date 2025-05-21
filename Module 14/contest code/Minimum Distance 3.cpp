#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj;
vector<int>dis;

void bfs(int root){
    deque<int>dq;
    dq.push_front(root);
    dis[root]=0;
    while(!dq.empty()){
        int parent=dq.front();
        dq.pop_front();
        for(auto pp : adj[parent]){
            int child=pp.first;
            int weight=pp.second;
            if(dis[child]>dis[parent]+weight){
                dis[child]=dis[parent]+weight;
                if(weight==0){
                    dq.push_front(child);
                }
                else{
                    dq.push_back(child);
                }
            }
            
        }
    }
}
     
int main() {
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    dis.resize(n+1,1e9);
    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(dis[i]==1e9) cout<<-1<<" ";
        else cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}