int f(int i , int w ,int n, vector<int> &profit, vector<int> &weight, vector<vector<int > >&dp ){
    if(i== 0 )return w/weight[0] * profit[0];
    if(dp[i][w]!=-1)return dp[i][w];
    int notTake = f(i-1 , w,n , profit, weight , dp);
    int take = -1e9;
    if(weight[i]<= w){
        take = profit[i] + f(i , w - weight[i] , n, profit , weight, dp);
        
    }
    return dp[i][w] = max(take , notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int > >dp(n , vector<int >(w+1 , -1)) ;
    return f(n-1 , w , n, profit, weight, dp);
}


int f(int i , int w ,int n, vector<int> &profit, vector<int> &weight, vector<vector<int > >&dp ){
    if(i== 0 )return w/weight[0] * profit[0];
    if(dp[i][w]!=-1)return dp[i][w];
    int notTake = f(i-1 , w,n , profit, weight , dp);
    int take = -1e9;
    if(weight[i]<= w){
        take = profit[i] + f(i , w - weight[i] , n, profit , weight, dp);
        
    }
    return dp[i][w] = max(take , notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int > >dp(n , vector<int >(w+1 , 0)) ;
    for(int i =0 ;i<=w; i++){
        dp[0][i] = ((int)i/weight[0]) * profit[0];
    }
    for(int i= 1;i<n; i++){
        for(int j= 0;j<=w; j++){
            int notTake = dp[i-1][j];
            int take = -1e9;
            if(weight[i]<= j){
                take = profit[i] + dp[i][j - weight[i]];
        
            }
            dp[i][j] = max(take , notTake);
            
        }
    }
    return dp[n-1 ][w ];
}
s