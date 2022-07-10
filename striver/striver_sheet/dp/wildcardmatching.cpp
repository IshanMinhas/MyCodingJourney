#include<bits/stdc++.h>
bool wildcardMatching(string s1, string s2)
{
   // Write your code here.
	int n = s1.size();
	int m = s2.size();
	vector<vector<bool>> dp(n+1 , vector<bool> (m+1 , false));
	dp[0][0] = true;
	
	for(int j = 1 ;j <=m; j++) {dp[0][j] = false;}
	
	for(int i = 1; i<=n ;i++){
		 bool flag = true;
		 for(int k =1 ; k<=i ; k++){
			if(s1[k-1]!= '*'){
				flag = false;
				break;
			}
		 }
		dp[i][0] = flag;
	}
	
	
	for(int i = 1; i<= n ;i++){
		for(int j = 1 ; j<= m ; j++){
			if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
				dp[i][j] = dp [i-1][ j-1];
			}
			else if(s1[i-1] == '*'){
				dp[i][j] = dp[i][ j-1] or dp[ i-1][j];
				}
			else {dp[i][j] = false;}
			
		}
	}
	
	
	return dp [n][m];
	
	
}
