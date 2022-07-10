int f(int i , int j, string &t , string &s , vector<vector<int>> dp){
	if(j <0) return 1;
	if(i<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(t[i] == s[j]){
		return dp[i][j] =  f(i-1 , j-1 , t, s, dp) + f(i-1 , j, t, s, dp);
		
	}
	else{
		return dp[i][j] = f(i-1 , j , t, s, dp);
	}
	
	
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
	vector<vector<double>> dp(lt +1, vector<double> (ls+1 , 0));
	for(int i = 0; i<=lt ; i++) dp[i][0] = 1;
	
	for(int i = 1; i<=lt ;i++){
		for(int j = 1; j<=ls; j++){
			if(t[i-1] == s[j-1]){
				dp[i][j] =  dp[i-1 ][ j-1]+ dp[i-1] [ j];
			}
			else{
				dp[i][j] = dp[i-1][ j];
			}
		}
	}
	return (int)dp[lt][ ls ];
} 


// 2 arr
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
	vector<double> prev(ls +1 , 0) , cur(ls+1 , 0);
	prev[0] = cur[0] = 1;
	
	for(int i = 1; i<=lt ;i++){
		for(int j = 1; j<=ls; j++){
			if(t[i-1] == s[j-1]){
				cur[j] =  prev[ j-1]+ prev[ j];
			}
			else{
				cur[j] = prev[ j];
			}
		}
		prev = cur;
	}
	return (int)cur[ ls ];
} 
// 1aarr
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
	vector<double> prev(ls +1 , 0) ;
	prev[0] = 1;
	
	for(int i = 1; i<=lt ;i++){
		for(int j = ls; j>=1; j--){
			if(t[i-1] == s[j-1]){
				prev[j] =  prev[ j-1]+ prev[ j];
			}
			else{
				prev[j] = prev[ j];
			}
		}
	
	}
	return (int)prev[ ls ];
} 