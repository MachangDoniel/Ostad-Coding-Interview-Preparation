#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int s,e; cin>>s>>e;
        v.push_back({e,s});
    }
    sort(v.begin(),v.end());
    int end=0,count=0;
    for(int i=0;i<n;i++){
        int e=v[i].first;
        int s=v[i].second;
        if(s>=end){
            count++;
            end=e;
        }
    }
    cout<<count<<endl;
    return 0;
}