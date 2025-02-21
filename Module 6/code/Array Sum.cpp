#include <bits/stdc++.h>
using namespace std;
     
int call(int sumRest){
    if(sumRest==0) return 1;
    int count=0;
    for(int i=1;i<=sumRest;i++){
        count+=call(sumRest-i);
    }
    return count;
}

int main() {
    int sum; cin>>sum;
    cout<<call(sum)<<endl;
    return 0;
}