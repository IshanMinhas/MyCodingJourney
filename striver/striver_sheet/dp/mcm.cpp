#include<bits/stdc++.h>
int f(int i , int j , vector<int>&arr , int N, vector<vector<int>> &dp){
	if(i==j) return 0;
	int mini = 1e9;
	if(dp[i][j]!=-1) return dp[i][j];
	for(int k = i; k<=j-1 ; k++){
		int ops = arr[i-1]*arr[k]*arr[j] + f(i,k, arr, N,dp) + f(k+1 , j, arr, N, dp); 
		//mini = min(mini , ops);
		if(ops<mini) mini = ops;
	}
	return dp[i][j] = mini;
	
	
	
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
	//vector<vector<int>> dp(N , vector<int> (N , 0));
	int dp[N][N];
	for(int i = 1; i<N ; i++) dp[i][i]=0;
	
	for(int i =N-1 ; i>=1; i--){
		for(int j = i+1 ; j<N ;j++ ){
			int mini = 1e9;
	
			for(int k = i; k<=j-1 ; k++){
				int ops = arr[i-1]*arr[k]*arr[j] + dp[i][k]+ dp[k+1][ j]; 		
				if(ops<mini) mini = ops;
			}
				dp[i][j] = mini;
			
			
		}
	}
	return dp[1][ N-1];
}