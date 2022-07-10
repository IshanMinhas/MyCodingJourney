#define mod (int)(1e9+7)
int mazeObstacles(int n, int m, vector< vector< int> > &a) {
    // Write your code here
     vector<vector<int >> dp(a.size(), vector<int > (a[0].size(), 0));
 
    for(int i=0; i <a.size();i++){
        for(int j = 0; j<a[0].size();j++){
            if(a[i][j] == -1)dp[i][j] = 0;
            else if(i == 0 and j == 0) dp[i][j] =1; 
            else{
            int one = 0 , second = 0;
            if(i > 0)one = dp[i-1] [j];
            if(j > 0)second = dp[i][j-1];
            dp[i][j] = (one + second)%mod;   
            }}
        }
    
    return dp[a.size()-1][a[0].size()-1];
}