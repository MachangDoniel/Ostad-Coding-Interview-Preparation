// Sqaure Sum

// Problem Statement

// You are given an integer K. You have to tell the minimum number of square integers needed to make the sum equal to K.

// Square integers are integers which have integer square roots.
// 1, 4, 25 are square integers but 2, 10 are not.

// Input
// The input consists of one integer K.

// Output
// Print one integer, the minimum number of square integers needed to make the sum equal to K.

// Constraints
// 1 ≤ K ≤ 2*10^4

// Example 1:
// Input:
// 9
// Output:
// 1

// Example 2:
// Input:
// 6
// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    int K; cin>>K;

    vector<int>dp(K+1,1e9); // large value as INF
    dp[0]=0;

    // Precompute all square numbers up to K
    vector<int>squares;
    for(int i=1;i*i<=K;i++){
        squares.push_back(i*i);
    }

    // DP build-up
    for(int i=1;i<=K;i++){
        for(int sq:squares){
            if(i>=sq){
                dp[i]=min(dp[i],dp[i-sq]+1);
            }
        }
    }

    cout<<dp[K]<<endl;
    return 0;
}