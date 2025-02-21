#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n; cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        v[i]={l,r};
    }
    sort(v.begin(),v.end());
    int end=-10e9;
    vector<pair<int,int>>result;
    for(int i=0;i<n;i++){
        int l=v[i].first;
        int r=v[i].second;
        if(l<=end){
            // overlap
            end=max(end,r);
            result[result.size()-1].second=end;
        }
        else{
            result.push_back({l,r});
        }
        end=max(end,r);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i].first<<" "<<result[i].second<<endl;
    }

    return 0;
}