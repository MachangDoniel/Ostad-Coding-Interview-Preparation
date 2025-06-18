// Grid Path

// You have a grid of size N × M. You can only move from a cell (a, b) to either (a+1, b) or (a, b+1). Initially, you are at cell (1, 1). You have to reach cell (N, M). How many distinct paths are there to reach (N, M)?

// Input:
// Two integers N and M.

// Output:
// Print the number of distinct paths modulo 10⁹ + 7.

// Constraints:
// 2 ≤ N, M ≤ 2000

// Example 1:
// Input:
// 2 2
// Output:
// 2

// Example 2:
// Input:
// 3 4
// Output:
// 10

// Notes:
// In Example 1, the two paths from (1,1) to (2,2) are:
// (1,1) → (1,2) → (2,2)
// (1,1) → (2,1) → (2,2)

#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main(){
    int n,m; cin>>n>>m;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[1][1]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1) continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}
