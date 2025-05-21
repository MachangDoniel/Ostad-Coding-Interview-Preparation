#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<int>group;
bool flag;

int assignGroup(int parentGrp){
    return parentGrp==1?2:1;
}

// follows bfs
void bfs(int node,int grp){
    queue<pair<int,int>>q;
    q.push({node,grp});
    while(!q.empty()){
        int parent=q.front().first;
        int parentGrp=q.front().second;
        q.pop();
        group[parent]=parentGrp;
        for(int child : adj[parent]){
            if(group[child]!=-1){
                if(group[child]==parentGrp){
                    flag=false;
                }
            }
            else q.push({child,assignGroup(parentGrp)});
        }
    }
}
     
int main() {
    cin>>n>>m;
    adj.resize(n+1);
    group.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    flag=true;
    for(int i=1;i<=n;i++){
        if(group[i]==-1){
            bfs(i,1);
        }
    }
    flag?cout<<"YES":cout<<"NO";
    cout<<endl;

    return 0;
}