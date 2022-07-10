class Solution {
public:
    int f(int i , int j ,string &word1 , string &word2 ,vector<vector<int > >&dp  ){
        if(i <0 )return 1 + j;
        if(j< 0 )return 1+i;
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i] == word2[j])return dp[i][j] = f(i-1, j-1, word1 , word2 ,dp);
        else{
            return dp[i][j]=  1 + min(f(i-1, j , word1, word2, dp), min(f(i , j-1 , word1, word2, dp), f(i-1, j-1, word1, word2,dp)));
        }
        
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(); int m = word2.size();
        
        vector<vector<int > >dp (n , vector<int > (m, -1));    
        return f(n-1 , m-1 ,word1, word2, dp);
    }
};
class Solution {
public:
   
    int minDistance(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        vector<int > prev(m+1, 0), cur(m+1, 0 ); 
       
        for(int i =0 ; i<= m; i++)prev[i] =i;
        for(int i = 1 ; i<=n ; i++){
            cur[0] = i;
		for(int j = 1; j<=m; j++){
			if(str1[i-1] == str2[j-1]){
				cur[j] = prev [ j-1];
			}
			else{
				cur[j] = 1+ min( cur[ j-1] , min( prev[ j], prev[ j-1] ));
			}
			
		}
            prev = cur;
	}
	return prev[m];
           
        
    }
};