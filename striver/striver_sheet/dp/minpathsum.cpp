#include<bits/stdc++.h>
int f(vector<vector<int>> &a, int m , int n , vector<vector<int > >&dp){
    if(m == 0 and n == 0 )return a[m][n];
    if(m< 0 or n< 0)return 1e9;
    if(dp[m][n]!= -1)return dp[m][n];
    int left = a[m][n] + f( a, m, n-1, dp);
    int up = a[m][n] + f(a, m-1 , n, dp);
    
    return dp[m][n] = min(up , left);
    
    
    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(); int n= grid[0].size(); 
    vector<vector<int >> dp(m , vector<int > (n , -1 ));
    return f(grid, m- 1, n- 1, dp);
}


#include<bits/stdc++.h>
int f(vector<vector<int>> &a, int m , int n , vector<vector<int > >&dp){
    if(m == 0 and n == 0 )return a[m][n];
    if(m< 0 or n< 0)return 1e9;
    if(dp[m][n]!= -1)return dp[m][n];
    int left = a[m][n] + f( a, m, n-1, dp);
    int up = a[m][n] + f(a, m-1 , n, dp);
    
    return dp[m][n] = min(up , left);
    
    
    
}

int minSumPath(vector<vector<int>> &a) {
    // Write your code here.
    int m = a.size(); int n= a[0].size(); 
    vector<vector<int >> dp(m , vector<int > (n ,  0));
    for(int i = 0 ;i < m ; i++){
        for(int j = 0; j<n ; j++){
              
            if(i == 0 and j == 0 ) dp[i][j] = a[i][j];
            else{
                int left =0; int up =0;
               if(i<= 0 ) up = 1e9; if(j<= 0)left = 1e9; 
              if(j>0) left = a[i][j] + dp [i][j-1];    
              if(i>0) up = a[i][j]+ dp[i-1] [j];
                
                dp[i][j] = min(up , left);  
                }
            
        }
    }
  
    
    return dp[m- 1][ n- 1];
}