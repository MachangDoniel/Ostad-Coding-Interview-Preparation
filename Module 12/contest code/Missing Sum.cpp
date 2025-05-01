#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int target=1;
    for(int i=0;i<n;i++){
        if(target>=v[i]){
            target+=v[i];
        }
        else break;
    }
    cout<<target<<endl;

    return 0;
}