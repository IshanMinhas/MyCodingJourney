#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int f(int n1, int n2, vector<vector<int>> &dp , string  s1 , string s2){

    if(n1 ==0 ){
        return n2;
    }
    if(n2 == 0){
        return n1;
    }
    if(dp[n1][n2]!= -1){
        return dp[n1][n2];
    }

    if(s1[n1-1] == s2[n2-1]){
        return dp[n1][n2] = f(n1-1 , n2-1 , dp , s1 ,s2);
    }
    else{
    int op1 = f(n1  , n2-1 ,dp, s1 ,s2); //insert
    int op2 = f(n1 -1 , n2 -1 , dp , s1 , s2); //    replace
    int op3 = f(n1-1 , n2 , dp  ,s1 , s2);// remove
    return dp[n1][n2] =  1+ min(op1 , min(op2, op3));

    }
}

int main(){
    string s1 = "sunday";
    string s2 = "saturday";

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1+1 , vector<int> (n2+1 , -1));
    return f(n1 , n2 , dp, s1 , s2);

}