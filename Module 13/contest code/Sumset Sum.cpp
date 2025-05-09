#include <bits/stdc++.h>
using namespace std;

int n,x;
vector<int>v;

bool flag;

void call(int index,int current_sum){
    if(current_sum==x){
        flag=true;
        return;
    }

    if(index==n) return;

    call(index+1,current_sum);
    call(index+1,current_sum + v[index]);

}
    
int main() {
    cin>>n>>x;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    flag=false;

    call(0,0);
    
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}