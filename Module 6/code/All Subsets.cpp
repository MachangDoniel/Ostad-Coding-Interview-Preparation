#include <bits/stdc++.h>
using namespace std;

string s;
vector<string>res;

void call(int idx){
    if(idx==s.size()) return;
    int n=res.size();
    for(int i=0;i<n;i++){
        res.push_back(res[i]+s[idx]);
    }
    call(idx+1);
}

int main() {
    cin>>s;
    res.push_back("");
    string str;
    str+=s[0];
    res.push_back(str);
    call(1);
    sort(res.begin(),res.end());
    for(int i=1;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}