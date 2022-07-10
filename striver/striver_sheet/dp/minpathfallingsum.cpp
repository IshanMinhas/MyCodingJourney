    #include<bits/stdc++.h> 
int f(int i , int j , vector<vector<int>> &matrix , vector<vector<int>> &dp, int m ){
    
    if(j < 0 || j>= m) return -1e9;
    if(i == 0 ) return matrix[0][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int op1 = matrix[i][j] + f(i-1 , j, matrix, dp,m);
    int op2 = matrix[i][j] + f(i-1 , j -1, matrix, dp,m);
    int op3 = matrix[i][j] + f(i-1 , j+1 , matrix, dp,m);
    return dp[i][j] = max(op1, max(op2, op3));
}



int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int maxi = -1e9; int n = matrix.size(); int m =matrix[0].size(); 
    vector<vector<int >> dp( n , vector<int > (matrix[0].size(), -1));
    for(int j= 0;j<matrix[0].size() ; j++){
        int ans = f(n-1 , j , matrix, dp,m);
        maxi = max(maxi , ans);
    }
    return maxi;
}







#include<bits/stdc++.h> 
int f(int i , int j , vector<vector<int>> &matrix , vector<vector<int>> &dp, int m ){
    
    if(j < 0 || j>= m) return -1e9;
    if(i == 0 ) return matrix[0][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int op1 = matrix[i][j] + f(i-1 , j, matrix, dp,m);
    int op2 = matrix[i][j] + f(i-1 , j -1, matrix, dp,m);
    int op3 = matrix[i][j] + f(i-1 , j+1 , matrix, dp,m);
    return dp[i][j] = max(op1, max(op2, op3));
}



int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int maxi = -1e9; int n = matrix.size(); int m =matrix[0].size(); 
    vector<vector<int >> dp( n , vector<int > (m, 0));
    
    for(int j = 0; j<m ;j++ )dp[0][j] = matrix[0][j];
    
    for(int i = 1; i<n ;i++){
        for(int j = 0;j<m ; j++){ 
            int op1 = matrix[i][j] + dp[i-1 ][j];
            int op2 = matrix[i][j] ; if(j-1 >= 0) op2 += dp[i-1][j -1] ;else op2+= -1e9;
            int op3 = matrix[i][j] ; if(j< m -1) op3+= dp[i-1 ][ j+1];else op3+=-1e9;
            dp[i][j] = max(op1, max(op2, op3));
        }
    }
    
    
    for(int j= 0;j<m; j++){
        int ans = dp[n-1][ j ];
        maxi = max(maxi , ans);
    }
    return maxi;
}