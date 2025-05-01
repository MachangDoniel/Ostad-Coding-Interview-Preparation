#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int n,int x){
    return x*x+(n-x)*(n-x);
}

int32_t main() {
    int n; cin>>n;
    cout<<f(n,n/2)<<endl;
    return 0;
}