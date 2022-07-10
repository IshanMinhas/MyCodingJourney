#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool canPlace(int board[][20] , int n ,int x , int  y){

    // column
    for(int k =0 ; k<x ;k++ ){
        if(board[k][y] == 1){
            return false ;
        }
    }
    // left diag
    int i=x;
    int j =y;
    while(i>=0 and j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }
// right diag
    while(i>=0 and j<n){
        if(board[i][j] =1){
            return false;
        }
        i--;
        j++;
    }
    return true;



}
void printBoard(int n , int board[][20]){

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j< n ; j++){
            cout<< board[i][j] << "";
        }
        cout<< endl;

    }
    cout<< endl;
}
bool SolveNQueen(int n , int board[][20] , int i){
    // base
    if(i == n){
        // print board
        printBoard(n,board);
        return true;
    }
    // rec case
    // only 1 queen in each row
    for(int j =0 ; j<n ; j++){
        //whether current i,j is safe or not
        if(canPlace(board , n , i ,j)){
            board[i][j] =1 ;
            bool successOrNot = SolveNQueen(n , board , i+1);
            if(successOrNot){
                return true;
            }
            // backtrack
            board[i][j]=0;

        }
    }
    // false shiuld be sent after checking all possible combin in row to porevious row
        return false;
}

int main(){
    int board[20][20] = {};
    int n;
    cin >> n;

}