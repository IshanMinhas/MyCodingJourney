#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int game(string s  , int i ,int j , vector<vector<int>> dp){
   
   int size =s.length() ; int j = size-1;
       int i = 0;
    if(size = 2){
        if(s[i] == 'O' and s[j] == 'O'){
            return 2;
        }
        else if(s[i] == 'H' and  s[j] == 'H'){
            return -3;
        }
        else if(s[i]!= s[j] and s[i] == 'O'){
            return -1;
        }
        else{
            return -1;
        }
    }
    
    
    if(size == 1){
        if(s[i] == 'H'){
            return -2;
        }
        else if(s[i] == 'O'){
            return 1;
        }
    }

    if(dp[i][j] != 0 ){
        return dp[i][j];
    }

    


    }




pair<char , int> GameofWits(string s){
    
    

}
int main(){
    string s = "HOOOOHHO" ;
    GameofWits(s);
}