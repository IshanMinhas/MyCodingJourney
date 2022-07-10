#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &a , int ind , int sum, vector<vector<int>> &dp ){
	// here there can be a prob when arr id[0,0,0,1] and sum = 1
	// then we will not get the total no of ways , but the ways will be 2^n*ans
	// and you just have to let it travel till the last index in the rec tree
	// remove sum == 0 condition
	// add
	/* if(ind ==0){
		if(sum == 0&& num[0] == 0 ) return 2;
		if( sum == 0 || sum == num[0])return 1;
		return 0;
	}
	*/
	if(sum == 0){
		return 1;
	}
	if(ind == 0) return(a[ind] == sum);
	
	if(dp[ind][sum]!= -1){
	return dp[ind][sum];}
	
	int notTake = f(a, ind-1 , sum, dp);
	int take = 0;
	if(a[ind] <= sum){
		take =  f(a , ind-1 , sum - a[ind], dp);
	}
	
	return dp[ind][sum] =  notTake + take;



}



int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n = num.size();
	vector<vector<int>> dp( n , vector<int> (tar + 1 , 0));
	for(int i = 0 ; i< n ; i++){
		dp[i][0] = 1;
	}
	if(num[0]<tar) dp[0][0] = 1;
	for(int ind=1; ind<=n; ind++){
		for(int sum=0; sum<=tar ; sum++){
			
			int notTake = dp[ ind-1 ][ sum];
			int take = 0;
			if(num[ind] <= sum){
				take =  dp[  ind-1 ][ sum ];
				}
	
				dp[ind][sum] =  notTake + take;
	
		}	
	}
	
	return dp[ n-1][ tar];
	
}