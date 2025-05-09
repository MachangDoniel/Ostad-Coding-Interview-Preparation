#include <iostream>
#include <vector>
using namespace std;

int n,x;
vector<int>v;

bool found;

void call2(int idx,int sum,int mask,int forbidden_mask){
    if(sum>x) return;
    if(sum==x){
        found=true;
        return;
    }
    if(idx==n || found) return;

    if(!(forbidden_mask & (1<<idx))){
        // nibo
        call2(idx+1,sum+v[idx],mask | (1<<idx),forbidden_mask);
    }
    //  nibona
    call2(idx+1,sum,mask,forbidden_mask);
}

void call(int idx,int sum,int mask){
    if(sum>x) return;
    if(sum==x){
        // call2(idx,sum,mask,forbidden_mask);
        call2(0,0,0,mask);
        return;
    }
    if(idx==n || found) return;

    // nibo
    // call(idx+1,sum+v[idx],mask + pow(2,idx));
    call(idx+1,sum+v[idx],mask | (1<<idx));

    // nibona
    call(idx+1,sum,mask);
    
}

int main() {
    cin>>n>>x;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    found=false;
    // call(idx,sum,mask)
    call(0,0,0);

    if(found) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
