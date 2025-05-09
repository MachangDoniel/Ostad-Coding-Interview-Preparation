#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>grid(9,vector<int>(9));

bool isSafe(int row,int col,int num){
    for(int i=0;i<9;i++){
        if(grid[row][i]==num) return false;
    }
    
    for(int i=0;i<9;i++){
        if(grid[i][col]==num) return false;
    }
    
    int startRow=row-row%3;
    int startCol=col-col%3;
    for(int i=startRow;i<startRow+3;i++){
        for(int j=startCol;j<startCol+3;j++){
            if(grid[i][j]==num) return false;
        }
    }
    
    return true;
}

bool solveSudoku(){
    int row,col;
    bool empty=false;
    
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(grid[row][col]==0){
                empty=true;
                break;
            }
        }
        if(empty) break;
    }
    if(!empty) return true;
    for(int num=1;num<=9;num++){
        if (isSafe(row,col,num)){
            grid[row][col]=num;
            if(solveSudoku()){
                return true;
            }
            grid[row][col]=0;
        }
    }

    return false;
}

void printGrid(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>grid[i][j];
        }
    }

    if(solveSudoku()){
        printGrid();
    }
    // else{
    //     cout<<-1<<endl;
    // }

    return 0;
}