#include <bits/stdc++.h>
using namespace std;


int findMinCell(int n,int m){
    int minCell=min(n,m);
    int power=31;
    while(minCell<pow(2,power)){
        power--;
    }
    return pow(2,power);
}

int call(int n,int m){
    if(n==0 || m==0) return 0;
    // cout<<n<<" "<<m<<endl;
    int cell=findMinCell(n,m);
    int nn=max(n,m);
    int mm=min(n,m);
    n=nn,m=mm;
    int div=n/cell;
    nn%=cell,mm%=cell;
    return call(n-nn,mm) + call(nn,m-mm) + call(nn,mm) + div;
}

int main() {
    int n,m; cin>>n>>m;
    cout<<call(n,m)<<endl;
    return 0;
}