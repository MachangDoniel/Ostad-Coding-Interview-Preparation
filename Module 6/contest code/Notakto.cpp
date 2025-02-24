#include <bits/stdc++.h>
using namespace std;

vector<string>mat(3);

bool getResult(){
    for(int i=0;i<3;i++){
        if(mat[i][0]=='X' && mat[i][1]=='X' && mat[i][2]=='X') return true;
        if(mat[0][i]=='X' && mat[1][i]=='X' && mat[2][i]=='X') return true;
    }
    if(mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X') return true;
    if(mat[2][0]=='X' && mat[1][1]=='X' && mat[0][2]=='X') return true;
    return false;
}

string playGame(string currentPlayer){
    bool winByCurrentPlayer=getResult();
    string nextPlayer;
    if(currentPlayer=="Alice") nextPlayer="Bob";
    else nextPlayer="Alice";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][j]=='.'){
                mat[i][j]='X';
                string winner=playGame(nextPlayer);
                if(winByCurrentPlayer==false && winner==currentPlayer){
                    winByCurrentPlayer=true;
                }
                mat[i][j]='.';
            }
        }
    }
    if(winByCurrentPlayer) return currentPlayer;
    else return nextPlayer;
}


void solve(){
    for(int i=0;i<3;i++){
        cin>>mat[i];
    }
    if(playGame("Alice")=="Alice") cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl; 
}
int main() {
    int t; cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Game "<<i<<": ";
        solve();
    }
    return 0;
}