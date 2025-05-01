#include <bits/stdc++.h>
using namespace std;
     
int main() {
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int index=0,count=0;
    while(index<n){
        if(s[index]=='0'){
            count++;
            index+=k;
        }
        else index++;
    }
    cout<<count<<endl;

    return 0;
}