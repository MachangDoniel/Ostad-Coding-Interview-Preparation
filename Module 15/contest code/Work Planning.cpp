#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>inD(n+1,0);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        inD[y]++;
    }
    set<pair<int,int>>s;
    for(int work=1;work<=n;work++){
        s.insert({inD[work],work});
    }
    int total_work=0;
    vector<int>works;
    while(!s.empty()){
        int inDegree=s.begin()->first;
        int parentWork=s.begin()->second;
        if(inDegree==0){
            s.erase(s.begin());
            total_work++;
            works.push_back(parentWork);
            for(int childWork : adj[parentWork]){
                s.erase(s.find({inD[childWork],childWork}));
                s.insert({--inD[childWork],childWork});
            }
        }
        else break;
    }
    if(total_work==n){
        for(int work : works){
            cout<<work<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;

    return 0;
}