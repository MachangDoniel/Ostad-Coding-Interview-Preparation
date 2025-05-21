#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<string>grid;
vector<vector<int>>dist;

bool valid(int r,int c){
    return 0<=r && r<n && 0<=c && c<m && grid[r][c]=='.';
}

void dfs(int r,int c){

    if(!valid(0,0) || !valid(n-1,m-1)){
        dist[n-1][m-1]=-1;
        return;
    }
    // destination
    if(r==n-1 && c==m-1){
        return;
    }
    // right
    if(valid(r,c+1)){
        if(dist[r][c+1]>dist[r][c]+1){
             dist[r][c+1]=dist[r][c]+1;
             dfs(r,c+1);
        }
    }
    // left
    if(valid(r,c-1)){
        if(dist[r][c-1]>dist[r][c]+1){
             dist[r][c-1]=dist[r][c]+1;
             dfs(r,c-1);
        }
    }
    // down
    if(valid(r+1,c)){
        if(dist[r+1][c]>dist[r][c]+1){
             dist[r+1][c]=dist[r][c]+1;
             dfs(r+1,c);
        }
    }
    // up
    if(valid(r-1,c)){
        if(dist[r-1][c]>dist[r][c]+1){
             dist[r-1][c]=dist[r][c]+1;
             dfs(r-1,c);
        }
    }
}

int bfs(int r,int c){

    queue<pair<int,int>>q;
    dist.assign(n,vector<int>(m,0));

    if(!valid(0,0) || !valid(n-1,m-1)){
        dist[n-1][m-1]=-1;
        return -1;
    }
    q.push({r,c});
    dist[0][0]=1;

    while(!q.empty()){
        pair<int,int>pp=q.front();
        int r=pp.first;
        int c=pp.second;
        q.pop();

        // if(r==n-1 && c==m-1){
        //     return dist[r][c];
        // }

        // right
        if(valid(r,c+1)){
            if(dist[r][c+1]==0){
                dist[r][c+1]=dist[r][c]+1;
                q.push({r,c+1});
            }
        }
        // left
        if(valid(r,c-1)){
            if(dist[r][c-1]==0){
                dist[r][c-1]=dist[r][c]+1;
                q.push({r,c-1});
            }
        }
        // down
        if(valid(r+1,c)){
            if(dist[r+1][c]==0){
                dist[r+1][c]=dist[r][c]+1;
                q.push({r+1,c});
            }
        }
        // up
        if(valid(r-1,c)){
            if(dist[r-1][c]==0){
                dist[r-1][c]=dist[r][c]+1;
                q.push({r-1,c});
            }
        }
    }
    return dist[n-1][m-1]==0?-1:dist[n-1][m-1];
    
}
     
int32_t main() {
    cin>>n>>m;
    grid.resize(n);
    dist.assign(n,vector<int>(m,LLONG_MAX));
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    // dist[0][0]=1;
    // dfs(0,0);
    // if(dist[n-1][m-1]==LLONG_MAX){
    //     dist[n-1][m-1]=-1;
    // }
    // cout<<dist[n-1][m-1]<<endl;
    cout<<bfs(0,0)<<endl;
    return 0;
}