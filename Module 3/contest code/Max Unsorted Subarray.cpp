#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>preMax(n),sufMin(n);
    preMax[0]=v[0];
    for(int i=1;i<n;i++){
        preMax[i]=max(preMax[i-1],v[i]);
    }
    sufMin[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        sufMin[i]=min(sufMin[i+1],v[i]);
    }
    int l=-1,r=-1;
    for(int i=0;i<n;i++){
        if(sufMin[i]!=preMax[i]){
            if(l==-1) l=i+1;
            else r=i+1;
        }
        // cout<<preMax[i]<<" "<<sufMin[i]<<endl;
    }
    if(l==-1) cout<<-1<<endl;
    else cout<<l<<" "<<r<<endl;
    return 0;
}