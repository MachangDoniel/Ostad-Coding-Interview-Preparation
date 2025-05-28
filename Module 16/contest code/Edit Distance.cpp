// Edit Distance
// Problem Statement
// You will be given two strings of size N and M. Below are the operations that can be performed on the first string. Find the minimum number of operations needed to convert the first string to the second string.

// Operations:
// Insert any character anywhere.
// Remove any character.
// Replace any character.

// Input
// Input consists of three lines. First one having two integers N and M. Second line has a string of length N. Third line has a string of length M.

// Output
// Print one integer, the minimum number of operations needed to convert the first string to the second string.

// Constraints
// 1 ≤ N, M ≤ 1000
// Every character of the strings will be lowercase Latin characters.

// Example 1:
// Input:
// 5 6
// parvj
// parvej
// Output:
// 1

// Example 2:
// Input:
// 3 3
// abc
// abc
// Output:
// 0

// Notes:
// On example 1, we can insert e between v and j to make string one equal to string two.



#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int inf=1e9;

int main() {
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    vector<vector<int>>dp(n+1,vector<int>(m+1,inf));
    a="#"+a;
    b="#"+b;
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][m]<<endl;
    return 0;
}
