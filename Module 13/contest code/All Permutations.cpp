#include <bits/stdc++.h>
using namespace std;
    
int n;
string s;
vector<bool>vis;
set<string>st;

void call(int numOfChar,string curr){
    if(numOfChar==n){
        st.insert(curr);
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            call(numOfChar+1,curr + s[i]);
            vis[i]=false;
        }
    }
}

int main() {
    cin>>n;
    vis.resize(n,false);
    cin>>s;
    // sort(s.begin(),s.end());
    // call(numOfChar,curr);

    call(0,"");

    for(string str:st){
        cout<<str<<endl;
    }

    return 0;
}