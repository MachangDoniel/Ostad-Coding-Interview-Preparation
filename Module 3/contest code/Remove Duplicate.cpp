#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n);
    int prev=-1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]!=prev){
            cout<<v[i]<<" ";
        }
        prev=v[i];
    }

    return 0;
}