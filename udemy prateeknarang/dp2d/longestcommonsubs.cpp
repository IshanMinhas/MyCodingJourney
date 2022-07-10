#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lcs_topdown(string s1, string s2, int i , int j, vector< vector< int>> &dp ){

 
    // return when reached end of eihter string 
    if(i == s1.length() or j == s2.length()){
        return 0;
    }
       
    // check if dp[i][j] is already filled
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // when char matching in both strings 
    if(s1[i] == s2[j]){
        return dp[i][j] =  1 + lcs_topdown(s1 , s2, i+1, j+1, dp);
    }
    // when char not matachign in both string
    int opt1 = lcs_topdown(s1 , s2 , i+1 , j, dp);
    int opt2 = lcs_topdown(s1 , s2, i , j+1, dp);

    return dp[i][j] = max(opt1 , opt2);



}

int lcs_bottom_up( string s1 , string s2){

    int n1 = s1.length();
    int n2 = s2.length();
    vector< vector< int >> dp1(n1+1 , vector< int >(n2+1 , 0));
    
    for(int i = 1; i<=n1 ; i++){
        for(int j = 1; j<=n2 ; j++){
            if(s1[i-1] == s2[j-1]){
                dp1[i][j] = 1 + dp1[i-1][j-1]; 
            }
            else{
                int op1 = dp1[i-1][j];
                int op2 = dp1[i][j-1];
                dp1[i][j] = max(op1 , op2);

            }



        }
       
    }



    vector<int> result;
    int i = n1; 
    int j = n2;
    while(i != 0 and j!=0){
        if(dp1[i][j]== dp1[i][j-1] ){
            j--;
        }
        else if(dp1[i][j] == dp1[i-1][j]){
            i--;

        }
        else{
            result.push_back((s1[i-1])); i--; j--;
        }




    }
    reverse(result.begin() , result.end());
    for(char x: result){
        cout << x << " ";
    }


 return dp1[n1][n2];




}




int main(){

    string s1 = " ABCD";
    string s2 = "ABEDG" ;
    // int n1 = s1.length();
    // int n2 = s2.length();
    // vector< vector< int>> dp(n1 , vector<int>(n2 , -1) );
    
    // max lcs
    // cout << lcs_topdown(s1 , s2, 0 ,0, dp) << endl;
    //  // print dp
    // for(int i = 0 ; i<n1 ; i++){
    //     for(int j = 0 ; j<n2 ; j++){

    //         cout << dp[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    cout << lcs_bottom_up(s1 , s2) << endl;



}