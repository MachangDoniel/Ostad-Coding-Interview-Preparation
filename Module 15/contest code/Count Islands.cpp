#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string>grid;
vector<vector<int>>island;

bool valid(int r,int c){
    return 0<=r && r<n && 0<=c && c<m && grid[r][c]=='.' && island[r][c]==0;
}

void dfs(int r,int c,int islandNo){
    island[r][c]=islandNo;
    //right
    if(valid(r,c+1)) dfs(r,c+1,islandNo);
    //left
    if(valid(r,c-1)) dfs(r,c-1,islandNo);
    //down
    if(valid(r+1,c)) dfs(r+1,c,islandNo);
    //up
    if(valid(r-1,c)) dfs(r-1,c,islandNo);
}
     
int main() {
    cin>>n>>m;
    grid.resize(n);
    island.resize(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    int islandNo=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(valid(i,j)){
                dfs(i,j,++islandNo);
            }
        }
    }
    cout<<islandNo<<endl;

    return 0;
}