// Stairs

// You have N stairs. Each time you can take 1, 2, or 3 steps. Calculate the number of ways to reach the Nth stair from stair 1.

// Input
// The input consists of one integer N.

// Output
// Print the number of ways to reach the Nth stair from stair 1 modulo 10^9 + 7.

// Constraints
// 2 ≤ N ≤ 10^5

// Example 1:
// Input:
// 2
// Output:
// 1

// Example 2:
// Input:
// 10
// Output:
// 149

// Note:
// In example 1, you start at stair 1 and can only take 1 step to reach stair 2.

#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main(){
    int n; cin>>n;
    vector<int>dp(n+1,0);

    dp[1]=1;
    if(n>=2) dp[2]=1;
    if(n>=3) dp[3]=2;

    for(int i=4;i<=n;i++){
        dp[i]=((dp[i-1]+dp[i-2])%MOD+dp[i-3])%MOD;
    }

    cout<<dp[n]<<endl;
    return 0;
}
