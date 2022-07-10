#include<bits/stdc++.h>
bool f(string &s1 , string &s2, int i ,int j, vector<vector<int>> &dp){
	if(i<0 && j<0){
		return true;
	}
	if(i<0 && j>=0){
		return false;
	}
	if(j<0 && i>=0){
		for(int k =0 ; i<=i ; k++){
			if(s1[k]!= '*'){
				return false;
			}
		else return true;
		}
	
	}
	if(dp[i][j]!=-1) return dp[i][j]; 
	
	if(s1[i] == s2[j] || s1[i] == '?'){
		return dp[i][j] = f(s1 ,s2, i-1  , j-1, dp);
	}
	else if(s1[i] == '*'){
		return dp[i][j] = f(s1 , s2 ,i, j-1 , dp) or f(s1 ,s2, i-1 ,j, dp);
	}
	return dp[i][j] = false;
	
	
	
	
	
	
}

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