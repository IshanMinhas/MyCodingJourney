#include<bits/stdc++.h>
int f(int ind , int buy , vector<int> &prices, vector<vector<int>> &dp){
	int n = prices.size();
	if(ind >= n) return 0;
	if(dp[ind][buy]!=-1) return dp[ind][buy];
	if(buy){
		return dp[ind][buy] = max(- prices[ind] + f(ind+1 , 0 , prices, dp) , 0 + f(ind +1, 1, prices, dp ));
		
	}
	else{
		return dp[ind][buy] = max(prices[ind] + f(ind + 2 , 1 , prices ,dp) , 0+ f(ind + 1 , 0 , prices, dp));
	}
	

	
	
}




int stockProfit(vector<int> &prices){
	int n = prices.size();
	vector<vector<int>> dp(prices.size() +2,vector<int> (2 , 0)); 
	for(int ind = n-1 ; ind >= 0 ; ind--){
		for(int buy =0 ; buy<= 1 ;buy++){
			if(buy){
				 dp[ind][buy] = max(- prices[ind] + dp[ind+1 ][ 0] , 0 + dp[ind +1][ 1] );
		
			}
			else{
				 dp[ind][buy] = max(prices[ind] + dp[ind + 2 ][ 1 ], 0+ dp[ind + 1][0 ]);
			}
	
		}
	}
	return dp[0][ 1 ];    
}

#include<bits/stdc++.h>
int stockProfit(vector<int> &prices){
	int n = prices.size();
	vector<int> cur(2 , 0);
	vector<int> after1(2 , 0); 
	vector<int> after2(2 , 0); 
	for(int ind = n-1 ; ind >= 0 ; ind--){
			
		cur[1] = max(- prices[ind] + after1[ 0] , 0 + after1[ 1] );		
			
		cur[0] = max(prices[ind] + after2[ 1 ], 0+ after1[0 ]);
			
		after2 = after1;
		after1 = cur;
		
	}
	return cur[ 1 ];    
}