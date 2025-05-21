// **Notakto**

// **Problem Statement**
// Alice and Bob are playing a game of Notakto. In a game of Notakto, there will always be a winner.

// Notakto is played on a 3×3 tic-tac-toe board with both players playing **X**. A game ends when the board contains **three consecutive Xs** in a row, column, or diagonal — at which point the **player who made the last move loses** the game.

// Given a configuration of the board, you have to find out the winner. **Alice always makes the first move**. Both players are very intelligent and always make optimal moves.

// **Input**
// You are given an integer **N**, the number of games.

// For each game, you are given a 3×3 grid. Each cell is either:

// * `X` (occupied)
// * `.` (empty)

// **Output**
// For each game, print the winner of that game, in the format:
// `Game x: winner`
// Here, **x** is the game number (starting from 1), and **winner** is either `Alice` or `Bob`.

// **Constraints**

// * 0 < N ≤ 100

// **Example 1**
// **Input:**

// ```
// 1
// .X.
// .X.
// ..X
// ```

// **Output:**

// ```
// Game 1: Bob
// ```

// **Example 2**
// **Input:**

// ```
// 2
// .X.
// .XX
// X.X
// ...
// .XX
// ...
// ```

// **Output:**

// ```
// Game 1: Bob  
// Game 2: Alice
// ```


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