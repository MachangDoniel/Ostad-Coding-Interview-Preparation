#include <bits/stdc++.h>
using namespace std;

#define int long long
     
int32_t main() {
    int n; cin>>n;
    int p=63,count=0;
    while(n>0){
        if(n>=pow(2,p)){
            n-=pow(2,p);
            count++;
        }
        p--;
    }
    cout<<count<<endl;

    return 0;
}