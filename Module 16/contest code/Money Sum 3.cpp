// Money Sum 3
// Problem Statement
// You are given N coins. Each coin has a positive integer value. You are also given an integer S. You have to use the coins to make a sum of S. You can use one coin any number of times. What is the number of distinct ways to make a sum of S.

// Input
// The input consists of two lines. First one having two integers N and S. The second line has N distinct integers, the value of each coin.

// Output
// Print one integer, the number of ways modulo 10⁹+7.

// Constraints
// 1 ≤ N ≤ 100
// 1 ≤ S ≤ 10⁶
// Every value of the coins is between 1 and 10⁶

// Example 1:
// Input:
// 3 3
// 1 2 3
// Output:
// 4

// Example 2:
// Input:
// 3 6
// 1 2 3
// Output:
// 24

// Example 3:
// Input:
// 3 3
// 2 4 5
// Output:
// 0

// Notes:
// On example 1,
// 1+1+1 = 3
// 1+2 = 3
// 2+1 = 3
// 3 = 3
// So, the answer is 4 % (10⁹ + 7) = 4.



#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf=1e9;
const int mod=1e9+7;
     
int32_t main() {
    int n,s; cin>>n>>s;
    vector<int>coins(n);
    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>dp(s+1,0);
    dp[0]=1;
    for(int i=0;i<=s;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0){
                dp[i]=(dp[i]+dp[i-coins[j]])%mod;
            }
        }
    }
    cout<<dp[s]<<endl;

    return 0;
}