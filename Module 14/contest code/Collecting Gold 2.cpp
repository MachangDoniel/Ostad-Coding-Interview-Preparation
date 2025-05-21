#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,q;
vector<string>grid;
vector<vector<int>>comp_id;
vector<pair<int,int>>queury;
map<int,int>comp_gold;


bool valid(int r,int c){
    return 0<=r && r<n && 0<=c && c<m && grid[r][c]!='#' && comp_id[r][c]==0;
}

int bfs(int sr,int sc,int id){
    int gold=0;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    comp_id[sr][sc]=id;
    if(grid[sr][sc]=='g') gold++;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        // right
        if(valid(r,c+1)){
            comp_id[r][c+1]=id;
            if(grid[r][c+1]=='g') gold++;
            q.push({r,c+1});
        }
        // left
        if(valid(r,c-1)){
            comp_id[r][c-1]=id;
            if(grid[r][c-1]=='g') gold++;
            q.push({r,c-1});
        }
        // down
        if(valid(r+1,c)){
            comp_id[r+1][c]=id;
            if(grid[r+1][c]=='g') gold++;
            q.push({r+1,c});
        }
        // up
        if(valid(r-1,c)){
            comp_id[r-1][c]=id;
            if(grid[r-1][c]=='g') gold++;
            q.push({r-1,c});
        }
    }
    return comp_gold[id]=gold;
}


void solve(){
    cin>>n>>m>>q;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    // comp_id.clear();
    comp_id.assign(n,vector<int>(m,0));
    comp_gold.clear();
    int id=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='#' && comp_id[i][j]==0){
                bfs(i,j,id++);
            }
        }
    }
    while(q--){
        int x,y; cin>>x>>y;
        x--,y--;
        cout<<comp_gold[comp_id[x][y]]<<endl;
    }

}
     
int32_t main() {
    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}