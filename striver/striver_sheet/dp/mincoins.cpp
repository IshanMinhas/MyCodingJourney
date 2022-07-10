int f(int i, int x,vector<int> &num,vector<vector<int >> &dp  ){
    if(x == 0 )return 0;
    if(i == 0 ){
           if(x%num[0]==0)return x/num[0];
           else return 1e9;
    }
    
    if(dp[i][x]!=-1)return dp[i][x];
    int notTake = 0 + f(i-1 ,x , num, dp);
    int Take = INT_MAX;
    if(num[i]<= x) {Take = 1 + f(i , x-num[i], num, dp);}
    return dp[i][x] = min(Take , notTake);
   
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int >> dp(n , vector<int > (x+1, 0));
    
    for(int i = 0; i<=x; i++){
        if(i%num[0] ==  0)dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }
    
    for(int i = 1; i<n ; i++){
        for(int j = 1; j<= x; j++){
            int notTake = 0 + dp[i-1 ][j ];
            int Take = INT_MAX;
            if(num[i]<= j) {Take = 1 + dp[i][ j-num[i]];}
            dp[i][j] = min(Take , notTake);
        }
    }
    
    
    
    
    
    
    
    
    int ans = dp[n-1][x];
    if(ans>= 1e9)return -1;
    return ans;
}