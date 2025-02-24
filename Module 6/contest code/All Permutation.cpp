#include <bits/stdc++.h>
using namespace std;

string s;
vector<string>res;

void call(string mask){
    if(mask.size()==s.size()){
        for(int i=0;i<s.size();i++){
            cout<<s[mask[i]-'0'];
        }
        cout<<endl;
        return;
    }   
    for(int i=0;i<s.size();i++){
        bool found=false;
        for(int j=0;j<mask.size();j++){
            if(i==(mask[j]-'0')) found=true;
        }
        if(!found){
            call(mask+char('0'+i));
        }
    }
}


int main() {
    cin>>s;
    sort(s.begin(),s.end());
    call("");
    for(string ss:res){
        cout<<ss<<endl;
    }
    return 0;
}