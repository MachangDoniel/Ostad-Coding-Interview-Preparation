#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,sr,sc;
vector<string>grid;


bool valid(int r,int c){
    return 0<=r && r<n && 0<=c && c<m && grid[r][c]!='#';
}

int bfs(int sr,int sc){
    int gold=0;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vis[sr][sc]=true;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        // right
        if(valid(r,c+1)){
            if(!vis[r][c+1]){
                vis[r][c+1]=true;
                if(grid[r][c+1]=='g') gold++;
                q.push({r,c+1});
            }
        }
        // left
        if(valid(r,c-1)){
            if(!vis[r][c-1]){
                vis[r][c-1]=true;
                if(grid[r][c-1]=='g') gold++;
                q.push({r,c-1});
            }
        }
        // down
        if(valid(r+1,c)){
            if(!vis[r+1][c]){
                vis[r+1][c]=true;
                if(grid[r+1][c]=='g') gold++;
                q.push({r+1,c});
            }
        }
        // up
        if(valid(r-1,c)){
            if(!vis[r-1][c]){
                vis[r-1][c]=true;
                if(grid[r-1][c]=='g') gold++;
                q.push({r-1,c});
            }
        }
    }
    return gold;
}
     
int32_t main() {
    cin>>n>>m>>sr>>sc;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    sr--,sc--;
    cout<<bfs(sr,sc)<<endl;
    // cout<<"Yes"<<endl;

    return 0;
}