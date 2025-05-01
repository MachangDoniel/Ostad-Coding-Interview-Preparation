#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int mxCount=1,currentCount=1;
    for(int i=1;i<n;i++){
        if(v[i-1]==v[i]) currentCount++;
        else{
            mxCount=max(mxCount,currentCount);
            currentCount=1;
        }
    }
    mxCount=max(mxCount,currentCount);
    cout<<mxCount<<endl;
    return 0;
}