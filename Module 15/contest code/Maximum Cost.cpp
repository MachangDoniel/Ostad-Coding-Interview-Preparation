#include<bits/stdc++.h>
using  namespace std;

#define int long long

vector<vector<pair<int,int>>>adj;
map<pair<int,int>,bool>mp;
vector<int>cost;

void call(int node,int destination){
    cost[node]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,node});
    while(!pq.empty()){
        int costToNode=pq.top().first;
        node=pq.top().second;
        pq.pop();
        //if(c<cost[x])continue;
        for(auto pp : adj[node]){
            int weight=pp.first;
            int child=pp.second;
            if(mp[{node,child}]) continue;
            if(costToNode+weight>cost[child]){
                mp[{node,child}]=1;
                cost[child]=costToNode+weight;
                pq.push({cost[child],child});
            }
        }
    }
}

int32_t main()
{
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    cost.resize(n+1,-1);

    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        adj[x].push_back({w,y});
    }
    int source,destination; cin>>source>>destination;

    call(source,destination);

    cout<<cost[destination]<<endl;
}