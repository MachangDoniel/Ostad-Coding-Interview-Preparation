#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string>ans;

void call(int index,string curr){

    if(index==n){
        ans.push_back(curr);
        return;
    }

    call(index+1,curr);
    call(index+1,curr + s[index]);
}
    
int main() {
    cin>>n;
    cin>>s;

    // call(index,current_string)
    call(0,"");

    sort(ans.begin(),ans.end());

    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}