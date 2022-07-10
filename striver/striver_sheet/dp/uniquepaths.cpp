#include <bits/stdc++.h>
int f(int i , int j, vector<vector<int >> dp){
    
    if(i == 0 and j== 0 )return 1;
    if(i<0 or j<0 )return 0;
    if(dp[i][j]!= -1)return dp[i][j];
    int one = f(i-1 ,j,dp);
    int second = f(i , j-1,dp);
    return dp[i][j] = one + second;   
}




int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int >> dp(m, vector<int > (n, 0));
 
    for(int i=0; i <m ;i++){
        for(int j = 0; j<n ;j++){
            if(i == 0 and j == 0) dp[i][j] =1; 
            else{
            int one = 0 , second = 0;
            if(i > 0)one = dp[i-1] [j];
            if(j > 0)second = dp[i][j-1];
            dp[i][j] = one + second;   
            }}
        }
    
    return dp[m-1][n-1];
}