#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>inD(n+1,0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        inD[y]++;
    }
    set<pair<int,int>>s;
    for(int city=1;city<=n;city++){
        s.insert({inD[city],city});
    }
    int ans=0;
    while(!s.empty()){
        int inDegree=s.begin()->first;
        int node=s.begin()->second;
        if(inDegree==0){
            s.erase(s.begin());
            ans++;
            for(int child : adj[node]){
                s.erase(s.find({inD[child],child}));
                s.insert({--inD[child],child});
            }
        }
        else break;
    }
    cout<<ans<<endl;

    return 0;
}