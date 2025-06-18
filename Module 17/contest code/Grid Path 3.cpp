// Grid Path 3

// You have a grid of size N * M. You can only move from a cell (a, b) to either (a+1, b) or (a, b+1). Initially, you are at cell (1, 1). You need to reach cell (N, M). Some cells are forbidden and cannot be visited.

// Input
// The first line contains two integers N and M.
// Then N lines follow, each containing M characters.

// # denotes a forbidden cell (cannot be visited).

// . denotes a free cell.

// Output
// Print the number of distinct paths from (1,1) to (N,M) modulo 10^9 + 7.

// Constraints
// 2 ≤ N, M ≤ 2000

// Example 1:
// Input:
// 2 2
// ..
// ..
// Output:
// 2

// Example 2:
// Input:
// 3 4
// .#..
// ..#.
// ....
// Output:
// 2

// Notes:
// In example 1, the two paths are:
// (1,1) → (1,2) → (2,2)
// (1,1) → (2,1) → (2,2)


#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main(){
    int n,m;
    cin>>n>>m;

    vector<string>grid(n+1); // 1-based indexing
    for(int i=1;i<=n;i++){
        cin>>grid[i];
        grid[i]=" "+grid[i]; // for 1-based indexing
    }

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    if(grid[1][1]!='#') dp[1][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='#') continue;
            if(i>1) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if(j>1) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}
