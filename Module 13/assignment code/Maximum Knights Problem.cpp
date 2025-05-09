#include <bits/stdc++.h>
using namespace std;

// Mathematical formula
int maxKnights(int n){
    if(n==1) return 1;
    if(n==2) return 4;
    return (n*n+1)/2;
}

int maxKnightsCount=0;

bool isSafe(int x,int y,vector<vector<bool>>&board,int n){
    int dx[]={-2,-1,1,2,2,1,-1,-2};
    int dy[]={1,2,2,1,-1,-2,-2,-1};

    for(int d=0;d<8;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx>=0 && ny>=0 && nx<n && ny<n && board[nx][ny])
            return false;
    }
    return true;
}

void backtrack(int x,int y,int placed,vector<vector<bool>>&board,int n) {
    if(x==n){
        maxKnightsCount=max(maxKnightsCount,placed);
        return;
    }

    int nx=(y==n-1)?x+1:x;      // go down if current row is checked
    int ny=(y==n-1)?0:y+1;      // start from column 0, if current row is checked

    // Try placing a knight
    if(isSafe(x,y,board,n)){
        board[x][y]=true;
        backtrack(nx,ny,placed+1,board,n);
        board[x][y]=false;
    }

    // Or skip this cell
    backtrack(nx,ny,placed,board,n);
}

int solve(int n){
    vector<vector<bool>>board(n,vector<bool>(n,false));
    maxKnightsCount=0;
    backtrack(0,0,0,board,n);
    return maxKnightsCount;
}

int main(){
    int n; 
    cin>>n;

    // time complexity = O(1)
    // cout<<maxKnights(n)<<endl;

    // time complexity = O(2^n^2), n=(1-6)
    cout<<solve(n)<<endl; 
    return 0;
}
