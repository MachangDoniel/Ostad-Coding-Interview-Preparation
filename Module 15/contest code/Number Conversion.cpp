#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
int conv[100005];

int bfs(int x,int y){
    queue<pair<int,int>>q;
    // number,noOfConversion
    q.push({x,0});
    while(!q.empty()){
        int num=q.front().first;
        int noOfConversion=q.front().second;
        q.pop();
        if(num==y){
            return noOfConversion;
        }
        // if(vis[num]) continue;
        // vis[num]=true;
        for(int child : adj[num]){
            if(conv[child]==-1){
                conv[child]=noOfConversion+1;
                q.push({child,noOfConversion+1});
            }
        }
    }
    return -1;
}

int main() {
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int p,q; cin>>p>>q;
        adj[p].push_back(q);
        conv[i]=-1;
    }
    int x,y; cin>>x>>y;
    
    int ans=bfs(x,y);
    (ans==-1)?cout<<"Impossible"<<endl:cout<<ans<<endl;

    return 0;
}