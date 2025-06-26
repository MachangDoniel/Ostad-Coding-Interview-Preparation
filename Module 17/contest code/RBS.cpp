// RBS

// Problem Statement

// You are given an integer N. How many different Regular Bracket Sequences can be generated using N Left and right Braces.

// Left brace is {
// Right brace is }

// Input
// The input consists of one integer N.

// Output
// Print one integer, the number of different Regular Bracket Sequences. The output will remain under 10^18.

// Constraints
// 1 ≤ N ≤ 30

// Example 1:
// Input:
// 3
// Output:
// 5

// Example 2:
// Input:
// 1
// Output:
// 1

// Note:
// The Regular Bracket Sequences for the first example are,
// {}{}{}
// {}{{}}
// {{}}{}
// {{}{}}
// {{{}}}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main() {
//     int n; cin>>n;
//     vector<ll>dp(n+1,0);
//     dp[0]=1;

//     for(int i=1;i<=n;i++){
//         for(int j=0;j<i;j++){
//             dp[i]+=dp[j]*dp[i-1-j];
//         }
//     }

//     cout<<dp[n]<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll catalan(int n) {
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        res = res * (2 * n - i) / (i + 1);
    }
    return res / (n + 1);
}

int main() {
    int N;
    cin >> N;
    cout << catalan(N) << endl;
    return 0;
}
