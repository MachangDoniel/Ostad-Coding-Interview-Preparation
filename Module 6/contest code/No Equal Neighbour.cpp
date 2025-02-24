#include <bits/stdc++.h>
using namespace std;

void call(int n,string str,char ch){
    if(n==0){
        cout<<str<<endl;
        return;
    }
    if(ch!='a') call(n-1,str+'a','a');
    if(ch!='b') call(n-1,str+'b','b');
    if(ch!='c') call(n-1,str+'c','c');

}

int main() {
    int n; cin>>n;
    call(n,"",'x');
    return 0;
}