#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,x; cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=v[i];
        if(sum>=x){
            cout<<n-i<<endl;
            return 0;
        }
    }

    return 0;
}