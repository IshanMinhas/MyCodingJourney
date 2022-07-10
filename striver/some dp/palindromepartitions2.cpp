#include<bits/stdc++.h>
bool palindrome(int i ,int j ,string &str){
	while(i < j ){
		if(str[i]!= str[j]) return false;
		i++;
		j--;
		
		
	}
	return true;
	
}


int f(int i , int n , string &str, vector<int> &dp){
	if(i==n)return 0;
	if(dp[i]!= -1) return dp[i];
	int minPartitions = INT_MAX;
	for(int j = i; j<n ; j++){
		if(palindrome( i , j , str)){
			int partitions = 1+ f(j+1 ,n , str, dp);
			minPartitions = min(minPartitions ,partitions);
		}
		
	}
return dp[i]= minPartitions;


}

int palindromePartitioning(string str) {
    // Write your code here
	int n = str.size();
	vector<int> dp(n ,-1);
	return f(0 ,n , str, dp)- 1;
}
