class Solution {
public:
    int f(string &s , int index , vector<int > &dp ){
        if(index < 0 )return 1;
        if(index == 0 && s[index]!= '0')return 1;
        if(index == 0 && s[index]==  '0')return 0;
        
        if(dp[index]!=-1 )return dp[index];
        int op1 = 0 ;
        int op2 = 0 ;
        
        if(s[index] != '0' ) op1 = f(s , index - 1, dp);
        if(s[index -1] == '1')  op2 = f(s , index- 2, dp );
        if(s[index - 1] == '2' and s[index] < '7') op2 = f(s , index- 2, dp );
        return dp[index] = op1 + op2 ;
        
        
    }
    
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int > dp(n , -1 );
        return f(s , n- 1, dp);
    }
};