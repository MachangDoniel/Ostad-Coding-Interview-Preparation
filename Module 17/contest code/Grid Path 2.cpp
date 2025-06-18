// Grid Path 2

// You have a grid of size N × M. You can only move from a cell (a, b) to either (a+1, b) or (a, b+1). Initially, you are at cell (1, 1). You have to reach cell (N, M). How many distinct paths are there to reach (N, M)?

// Input: The input consists of two integers N and M.
// Output: Print the number of distinct paths modulo 10⁹ + 7.

// Constraints: 2 ≤ N, M ≤ 10⁶

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
// In example 1, the two paths from (1,1) to (2,2) are:
// (1,1) → (1,2) → (2,2)
// (1,1) → (2,1) → (2,2)

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5; // because N + M can be up to 2*10^6

vector<long long>fact(MAX),invFact(MAX);

// Fast exponentiation
long long modPow(long long a,long long b){
    long long res=1;
    while(b){
        if(b & 1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0]=1;
    for (int i=1;i<MAX;i++)
        fact[i]=fact[i-1]*i%MOD;

    invFact[MAX-1]=modPow(fact[MAX-1],MOD-2);
    for (int i=MAX-2;i>=0;i--)
        invFact[i]=invFact[i+1]*(i+1)%MOD;
}

long long nCr(int n,int r){
    if(r<0 || r>n) return 0;
    return fact[n]*invFact[r]%MOD*invFact[n-r]%MOD;
}

int main() {
    int n,m;
    cin>>n>>m;
    precompute();

    cout<<nCr(n+m-2,n-1)<<endl;
    return 0;
}