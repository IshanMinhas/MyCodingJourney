#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
	vector<int> next (n +1, 0), cur(n+1 , 0);
	for(int ind = n-1 ; ind>=0 ; ind--){
		for(int prev = ind -1 ; prev>= -1 ; prev -- ){
			int len = 0	+ next [prev+1];
	
			if(prev == -1 or arr[ind] > arr[prev]){
					len = max(len , 1+ next[ ind+1 ]);}
			cur[prev+1] = len;
		}
		next = cur;
	}
	return next[ -1+1];
}


#include<bits/stdc++.h>
int f(int ind , int prev , int arr[] , int n , vector<vector<int>> &dp){
	if(ind == n)return 0;
	// not take
	
	if(dp[ind][prev + 1]!=-1) return dp[ind][prev+1];
	int len = 0	+ f( ind+1 , prev , arr,n, dp);
	if(prev == -1 or arr[ind] > arr[prev]){
		len = max(len , 1+ f(ind + 1 , ind , arr ,n, dp));
	}
	
	return dp[ind][prev+ 1] = len;
	
	
	
	
}