#include <bits/stdc++.h>
int f(int ind , int buy , int cap , vector<int> &prices, int n , vector<vector<vector<int>>> &dp){
		if(cap == 0) return 0;
		if(ind == n) return 0;
		if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
	
		if(buy == 1) {
			return dp[ind][buy][cap]= max(-prices[ind] + f(ind +1 , 0 , cap, prices , n, dp) , 0 + f(ind +1 , 1 , cap, prices , n, dp)); 
		}
		else{
			return dp[ind][buy][cap] = max(prices[ind] + f(ind+1 , 1 , cap-1, prices , n, dp) , 0+ f(ind+1 , 0 , cap, prices , n, dp) );
		}
	
}

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
	vector<vector<vector<int>>>dp(n , vector<vector<int>> (2 , vector<int> (3, -1)));
	return f(0 , 1 , 2 , prices , n, dp);
}

nt maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
	vector<vector<int>> cur(2 , vector<int> (3, 0));
	vector<vector<int>> after(2 , vector<int> (3, 0));
	
	
	for(int ind = n-1; ind>= 0; ind--){
		for(int buy=0 ;buy<=1; buy++ ){
			for(int cap = 1; cap<=2 ; cap++){
				if(buy == 1) {
					 cur[buy][cap]= max(-prices[ind] + after[ 0][ cap],  0 + after[ 1][ cap] ); 
				}
				else{
					 cur[buy][cap] = max(prices[ind] + after[1] [cap-1], 0+ after[ 0][cap] ) ;
				}
			}		
		}
		after = cur;
	}
	
	return cur[1 ][2] ;
}