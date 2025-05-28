// Binomial Coefficient
// Problem Statement
// Binomial Coefficient also represented as nCr.
// nCr = n-1Cr + n-1Cr-1
// You will be given n and r. You have to calculate the value of nCr modulo 10⁹+7.

// Input
// Input will have only two integers n and r.

// Output
// Print one integer, the value of nCr modulo 10⁹+7.

// Constraints
// 1 ≤ r ≤ n ≤ 5000

// Example 1:
// Input:
// 5 2
// Output:
// 10

// Example 2:
// Input:
// 3 3
// Output:
// 1

// Notes:
// On example 1, 5C2 = 10.
// and 10 % (10⁹+7) = 10.



#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int mod = 1e9+7;
     
int main() {
    int n,c; cin>>n>>c;
    vector<vector<int>>dp(n+1,vector<int>(c+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=min(c,i);j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=c;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][c]<<endl;

    return 0;
}