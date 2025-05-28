// Money Sum 2
// Problem Statement
// You are given N coins. Each coin has a positive integer value. You are also given an integer S. You have to use the coins to make a sum of S. You can use one coin any number of times. What is the minimum number of coins required to make a sum of S.

// Input
// The input consists of two lines. First one having two integers N and S. The second line has N distinct integers, the value of each coin.

// Output
// Print one integer, the minimum number of coins needed. If it is not possible to produce the desired sum, print −1.

// Constraints
// 1 ≤ N ≤ 100
// 1 ≤ S ≤ 10⁶
// Every value of the coins is between 1 and 10⁶

// Example 1:
// Input:
// 3 3
// 1 2 3
// Output:
// 1

// Example 2:
// Input:
// 3 6
// 1 2 3
// Output:
// 2

// Example 3:
// Input:
// 3 3
// 2 4 5
// Output:
// -1

// Notes:
// On example 2, 3+3 = 6, so the total coins used is 2. But on example 3, there is no way to make 3.



#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf=1e9;
     
int32_t main() {
    int n,s; cin>>n>>s;
    vector<int>coins(n);
    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>dp(s+1,inf);
    dp[0]=0;
    for(int i=0;i<=s;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[s]==inf) cout<<-1<<endl;
    else cout<<dp[s]<<endl;

    return 0;
}