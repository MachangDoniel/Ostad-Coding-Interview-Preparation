#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>>adj_mat(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--,y--;
        adj_mat[x][y]=1;
        adj_mat[y][x]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}