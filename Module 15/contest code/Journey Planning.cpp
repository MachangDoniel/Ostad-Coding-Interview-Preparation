#include <bits/stdc++.h>
using namespace std;

map<string,int>mp={
    {"Dhaka",0},
    {"Khulna",1},
    {"Sylhet",2},
    {"Rangpur",3},
    {"Rajshahi",4}
};
vector<vector<pair<int,int>>>adj(5);
int dist[5];

int diskstra(int source,int destination){
    priority_queue<pair<int,int>>pq;
    // cost,city
    fill(dist, dist + 5, INT_MAX);
    dist[source]=0;
    pq.push({dist[source],source});
    
    while(!pq.empty()){
        int cost=-pq.top().first;
        int parent=pq.top().second;
        pq.pop();
        if(parent==destination){
            return cost;
        }

        for(auto pp : adj[parent]){
            int child=pp.first;
            int weight=pp.second;
            if(cost+weight<dist[child]){
                dist[child]=cost+weight;
                pq.push({-dist[child],child});
            }
        }
    }
    return -1;
}
     
int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string from,to; cin>>from>>to;
        int w; cin>>w;
        adj[mp[from]].push_back({mp[to],w});
    }
    string source,destination; cin>>source>>destination;

    cout<<diskstra(mp[source],mp[destination])<<endl;
    
    return 0;
}