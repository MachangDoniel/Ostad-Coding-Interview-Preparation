#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,m; cin>>n>>m;
    vector<int>a(1000001,0),b(1000001,0),ans;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a[x]++;
    }
    for(int j=0;j<m;j++){
        int y; cin>>y;
        b[y]++;
    }
    for(int i=0;i<1000001;i++){
        for(int j=0;j<min(a[i],b[i]);j++){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int value:ans){
        cout<<value<<" ";
    }
    cout<<endl;

    return 0;
}