// Fibonacci
// Problem Statement
// The Fibonacci sequence is one of the most famous sequences. ith Fibonacci number is represented as Fi. We know, F₀ = 0 and F₁ = 1, and Fi = Fi−1 + Fi−2. You have to print the nth Fibonacci number modulo 10⁹+7.

// Input
// Input will have only one integer n.

// Output
// Print one integer, the value of Fn modulo 10⁹+7.

// Constraints
// 2 ≤ n ≤ 10⁶

// Example 1:
// Input:
// 5
// Output:
// 5

// Example 2:
// Input:
// 2
// Output:
// 1

// Notes:
// On example 1,
// F₀ = 0
// F₁ = 1
// F₂ = 1
// F₃ = 2
// F₄ = 3
// F₅ = F₄ + F₃ = 5.



#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;
const int mod=1e9+7;

vector<int>f;

int fib(int n){
    if(f[n]!=inf) return f[n];
    if(n==0 || n==1) return f[n]=n;
    return f[n]=(fib(n-1)+fib(n-2))%mod;
}

int main() {
    int n; cin>>n;
    f.resize(n+1,inf);
    cout<<fib(n)<<endl;
    return 0;
}