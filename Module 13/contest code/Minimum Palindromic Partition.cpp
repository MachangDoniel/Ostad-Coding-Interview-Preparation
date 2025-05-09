#include <bits/stdc++.h>
using namespace std;

bool isPalidrome(string &s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int Call(string &s,int start){
    if(start==s.size()) return 0;
    int minCount=INT_MAX;

    for(int end=s.size()-1;end>=start;end--){
        if(isPalidrome(s,start,end)){
            int partition=1+Call(s,end+1);
            minCount=min(minCount,partition);
        }
    }
    return minCount;
}

void solve(){
    string s; cin>>s;
    int result=Call(s,0);
    cout<<result<<endl;
}
     
int main() {
    int T; cin>>T;
    while(T--){
        solve();
    }

    return 0;
}