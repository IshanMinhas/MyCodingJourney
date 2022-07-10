class Solution {
public:
    bool possible(int i ,int j ,string &str){
     while(i < j ){
		if(str[i]!= str[j]) return false;
		i++;
		j--;
		
		
	}
	return true;
	
    }
    int f(int i, string &s, vector<int> &dp){
        if(i == s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = 1e9;
        for(int j= i; j< s.size() ;j ++){
            string temp = s.substr(i, j-i+1);
            if(possible(i , j ,temp)){
                int cost = 1 + f(j+1 ,s, dp); 
                mini = min(cost, mini);
            }
        }
        return dp[i] = mini;
    } 
    int minCut(string s) {
        int n = s.size();
        vector<int > dp(s.size()+1, 0);
        dp[n] = 0;
        for(int i =n-1; i>=0 ;i--){
                int mini = 1e9;
                for(int j= i; j< s.size() ;j ++){
              
                if(possible(i ,j ,s)){
                    int cost = 1 + dp[j+1]; 
                    mini = min(cost, mini);
                }
            }
         dp[i] = mini;
        }
        return dp[0] - 1;
    }
};