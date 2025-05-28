// LCS
// Problem Statement
// You will be given two strings of size N and M. You have to find the length of the longest common subsequence of the two strings.

// Input
// Input consists of three lines. The first one has two integers N and M. The second line has a string of length N. The third line has a string of length M.

// Output
// Print one integer, the length of the longest common subsequence of the strings.

// Constraints
// 1 ≤ N, M ≤ 1000
// Every character of the strings will be lowercase Latin characters.

// Example 1:
// Input:
// 5 3
// abcde
// bde
// Output:
// 3

// Example 2:
// Input:
// 3 3
// abc
// def
// Output:
// 0

// Notes:
// On example 1, the subsequence (bde) is common in both strings.



#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    a="#"+a;
    b="#"+b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}
