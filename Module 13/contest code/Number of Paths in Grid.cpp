#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>grid;

bool valid(int x,int y){
    return 0<=x && x<n && 0<=y && y<m && grid[x][y]==0;
}

int call(int x,int y){
    // [x][y]
    // no valid
    if(!valid(x,y)) return 0;
    // valid
    // destination
    if(x==n-1 && y==m-1){
        return 1;
    }
    // // right
    // int right=call(x,y+1);
    // // down
    // int down=call(x+1,y);
    // return right+down;
    return call(x,y+1) + call(x+1,y);
}

void solve(){
    cin>>n>>m;
    // grid.resize(n);
    grid.assign(n,vector<int>(m));
    for(int i=0;i<n;i++){
        // grid[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<call(0,0)<<endl;
}
     
int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}