class Solution {
public:
    int f(int i1 , int i2, string text1, string text2 , vector<vector<int >> &dp){
        if(i1 <0 || i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        
        if(text1[i1] == text2[i2])return dp[i1][i2] =  1 + f(i1-1 , i2-1 , text1 , text2 , dp);
        else{
            return dp[i1][i2] = max(f(i1 , i2-1 , text1 , text2 , dp) , f(i1-1 , i2 , text1 , text2 , dp));  
        }
        
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); int m = text2.size();
        vector<vector<int >> dp(n +1, vector<int > (m +1, 0));

        for(int i1 = 1 ;i1<=n; i1++){
            for(int i2 = 1 ;i2<=m; i2++){
                if(text1[i1-1] == text2[i2-1]) dp[i1][i2] =  1 + dp[i1-1][i2-1];
                else{
                     dp[i1][i2] = max(dp[i1] [i2-1], dp[i1-1][i2]) ;  
                }
            }
        }
   
        return dp[n] [m ];
    }
};