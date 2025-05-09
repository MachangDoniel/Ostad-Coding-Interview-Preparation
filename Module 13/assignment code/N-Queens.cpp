#include <bits/stdc++.h>
using namespace std;

int n,no_of_ways;
vector<int>col,diag1,diag2;

void dfs(int row){
    if(row==n){
        no_of_ways++;
        return;
    }
    for(int c=0;c<n;c++){
        if(!col[c] && !diag1[row+c] && !diag2[row+n-c]){
            col[c]=diag1[row+c]=diag2[row+n-c]=1;
            dfs(row+1);
            col[c]=diag1[row+c]=diag2[row+n-c]=0;
        }
    }
}

int NQueens(){
    no_of_ways=0;
    col.resize(n);
    diag1.resize(2*n),diag2.resize(2*n);
    dfs(0);
    return no_of_ways;
}

int main(){
    cin>>n;
    cout<<NQueens()<<endl;
    return 0;
}
