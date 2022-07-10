class Solution {
public:
   bool f(int i, int j , string &s1, string &s2, string &s3, vector<vector<int >> &dp, int k ){
       if(k == s3.size() and i == s1.size() and j== s2.size())return true; 
       if(dp[i][j]!=-1)return dp[i][j]; 
        bool res = false;
        if(s1[i] == s3[k] and i!=s1.size()) res = res ||  f(i+1 , j, s1, s2, s3, dp , k+1);  
         if(s2[j] == s3[k] and j!= s2.size()) res = res ||  f(i , j+1 ,s1, s2,s3, dp , k+1 ) ; 
     
       return dp[i][j] = res;
           
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
       int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        bool ans=f(0 , 0 ,s1, s2,s3,dp , 0);
        return ans;
    }
};