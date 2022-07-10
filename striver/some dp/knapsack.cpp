#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// rec + top down
int f(int ind , int W , vector<int> &wt , vector<int> &val,vector<vector<int>> &dp ){
	if(ind == 0){
		if(wt[0] <= W){
			return val[0];
		}
		else return 0;
	}
	
	if(dp[ind][W] != -1){
		return dp[ind][W];
	}
	
	int NotTake = 0 + f(ind-1 , W ,wt , val, dp );
	int Take = INT_MIN;
	if(wt[ind] <= W){
		Take = val[ind] + f(ind-1 , W- wt[ind] , wt , val, dp);
		
	}
	return dp[ind][W] = max(NotTake , Take);
	


}


// bottom up tabulation
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n , vector<int>(maxWeight + 1 , 0));
	
	for(int W =	wt[0] ; W<= maxWeight ; W++) dp[0][W] = val[0];
	for(int ind= 1 ; ind< n; ind++){
		for(int W= 0; W<=maxWeight ; W++){
			int NotTake = 0 + dp[ind-1][ W ];
			int Take = INT_MIN;
			if(wt[ind] <= W){
				Take = val[ind] + dp[ind-1 ] [W- wt[ind]] ;
		
				}
			dp[ind][W] = max(NotTake , Take);
		}
	}
	
	
	
	return dp[n-1][maxWeight];
	
	
}

// 2 rows
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight +1 , 0) , cur(maxWeight + 1 , 0);
	
	
	for(int W =	wt[0] ; W<= maxWeight ; W++) prev[W] = val[0];
	for(int ind= 1 ; ind< n; ind++){
		for(int W= 0; W<=maxWeight ; W++){
			int NotTake = 0 + prev[ W ];
			int Take = INT_MIN;
			if(wt[ind] <= W){
				Take = val[ind] + prev[W- wt[ind]] ;
		
				}
			cur[W] = max(NotTake , Take);
		}
		prev = cur;
	}
	
	
	
	return prev[maxWeight];
	
	
}

// 1 row
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight +1 , 0);
	
	
	for(int W =maxWeight ; W>=wt[0] ; W--) prev[W] = val[0];
	for(int ind= 1 ; ind< n; ind++){
		for(int W= maxWeight; W>=0 ; W--){
			int NotTake = 0 + prev[ W ];
			int Take = INT_MIN;
			if(wt[ind] <= W){
				Take = val[ind] + prev[W- wt[ind]] ;
		
				}
			prev[W] = max(NotTake , Take);
		}
		
	}
	
	
	
	return prev[maxWeight];
	
	
}