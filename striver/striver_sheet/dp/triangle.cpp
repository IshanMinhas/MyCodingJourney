int f(int i, int j ,int n , vector<vector<int >> &a , vector<vector< int>> &dp){
    if(i == n-1)return a[i][j];
    
    
    if(i < 0 or i> a.size() or j <0 or j> a[j-1].size())return 0;
    if(dp[i][j]!= -1 )return dp[i][j];
    int opt1 = a[i][j] + f(i+1, j,n ,a , dp );
    int opt2 = a[i][j] + f(i +1 , j+1,n, a, dp);
    return dp[i][j] = min(opt2 ,opt1);

}


int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int  >> dp(n , vector<int > (triangle[n-1 ].size() , -1) );
    
  
    
    return f(0 , 0,n , triangle, dp);
    
}



int f(int i, int j ,int n , vector<vector<int >> &a , vector<vector< int>> &dp){
    if(i == n-1)return a[i][j];
    
    
    if(i < 0 or i> a.size() or j <0 or j> a[j-1].size())return 0;
    if(dp[i][j]!= -1 )return dp[i][j];
    int opt1 = a[i][j] + f(i+1, j,n ,a , dp );
    int opt2 = a[i][j] + f(i +1 , j+1,n, a, dp);
    return dp[i][j] = min(opt2 ,opt1);

}


int minimumPathSum(vector<vector<int>>& triangle, int n){
    // Write your code here.
    vector<int > dp(n , 0) ;
    for(int j=0 ;j<n ; j++ ){
        dp[j] = triangle[n-1][j];
    }
  for(int i = n-2 ; i>= 0 ;i--){
      vector<int > cur(n, 0 );
       for(int j = i; j>=0; j--){
           int opt1 = triangle[i][j] + dp[ j];
           int opt2 = triangle[i][j] + dp[j+1];
           cur[j] = min(opt2 ,opt1);
       }
      
      dp = cur;
  }
    
    return dp[0];
    
}