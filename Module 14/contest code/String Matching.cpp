#include <bits/stdc++.h>
using namespace std;

int callBfs(string s,string t){
    if(s==t) return 0;
    unordered_set<string>visited;
    queue<pair<string,int>>q;

    visited.insert(s);
    q.push({s,0});

    while(!q.empty()){
        string curr=q.front().first;
        int count=q.front().second;
        q.pop();

        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                string next=curr;
                swap(next[i],next[j]);
                if(next==t) return count+1;
                if(visited.count(next)==0){
                    visited.insert(next);
                    q.push({next,count+1});
                } 
            }
        }
    }
    return -1;
}
     
int main() {
    string s,t; cin>>s>>t;
    cout<<callBfs(s,t)<<endl;

    return 0;
}