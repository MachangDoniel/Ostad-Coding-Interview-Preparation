#include <bits/stdc++.h>
using namespace std;

int n,m,k,T,x,y;
bool found;
vector<vector<bool>>grid;

bool valid(int r,int c){
    return 0<=r && r<n && 0<=c && c<m && grid[r][c]==true;
}

bool checkFound(int r,int c,int t){
    if(r==x && c==y && t<=T) return true;
    return false;
}

void dfs(int r,int c,int t){
    grid[r][c]=false;
    if(checkFound(r,c,t)){
        found=true;
        return;
    }
    if(r>x || c>y) return;
    //right
    if(valid(r,c+1)) dfs(r,c+1,t+1);
    //down
    if(valid(r+1,c)) dfs(r+1,c,t+1);
}
     
int main() {
    cin>>n>>m>>k>>T;
    cin>>x>>y;
    x--,y--;
    grid.resize(n,vector<bool>(m,true));
    for(int i=0;i<k;i++){
        int r,c; cin>>r>>c;
        r--,c--;
        grid[r][c]=false;
    }
    found=false;
    dfs(0,0,0);
    found?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}