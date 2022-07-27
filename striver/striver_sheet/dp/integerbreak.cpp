class Solution {
public:
    int n;
    int f(int ind , vector<int > &dp){
        if(ind == 0 || ind == 1 )return 1 ;
        if(dp[ind]!= -1)return dp[ind];
        int maxi = 0;
        for(int i=1;i<ind; i++){
            int take = i * f(ind-i ,dp );
            maxi = max(take, max(maxi, i * (ind - i)));
        }
            
        return dp[ind] = maxi;    
            
    }
    int integerBreak(int n) {
        vector<int > dp(n+1 , - 1);
        return f(n  , dp );
    }
};