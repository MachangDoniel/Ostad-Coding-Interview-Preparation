#include <bits/stdc++.h>
using namespace std;

#define int long long

bool good(int n){
    vector<int>fact;
    int f=1;
    for(int i=1;f<=n;i++){
        f*=i;
        fact.push_back(f);
    }
    for(int i=fact.size()-1;i>=0;i--){
        if(fact[i]<=n){
            n-=fact[i];
        }
        if(n==0) return true;
    }
    return false;
    
}
     
int32_t main() {
    int n; cin>>n;
    if(good(n)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}