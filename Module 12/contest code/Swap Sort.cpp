#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<n+1;i++){
        cin>>v[i];
    }
    int count=0;
    vector<bool>vis(n+1,false);
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            int cycle_size=0;
            int idx=i;
            while(!vis[idx]){
                vis[idx]=true;
                idx=v[idx];
                cycle_size++;
            }
            count+=(cycle_size-1);
        }
        
    }
    cout<<count<<endl;

    return 0;
}