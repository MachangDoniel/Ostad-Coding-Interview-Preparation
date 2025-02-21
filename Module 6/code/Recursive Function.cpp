#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,ll>mp;

ll call(ll k){
    if(k==0) return mp[k]=1;
    if(mp[k]==0){
         return mp[k]=call(k/2)+call(k/3);
    } 
    else return mp[k];
}

int main() {
    ll n;
    cin>>n;
    ll sum=call(n);
    cout<<sum<<endl;
    return 0;
}