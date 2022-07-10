#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int f(vector<int> &a , int ind , int sum, vector<vector<int>> &dp ){
	
	
	if(ind == 0) {
		if(sum == 0 && a[0] == 0)return 2;
		if(sum == 0 || sum== a[0]) return 1;
		return 0;
	}
	
	if(dp[ind][sum]!= -1){
	return dp[ind][sum];}
	
	int notTake = f(a, ind-1 , sum, dp);
	int take = 0;
	if(a[ind] <= sum){
		take =  f(a , ind-1 , sum - a[ind], dp);
	}
	
	return dp[ind][sum] = ( notTake + take)%mod;



}

int findWays(vector<int> &num, int tar){
	int n =  num.size();
	vector<vector<int>> dp(n , vector<int> (tar+1 , -1));
	return f(num , n-1 , tar , dp);
	
	
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
	int totalSum= 0;
	for(auto &it:arr) totalSum += it;
	if((totalSum - d )<0 or (totalSum -d)%2) return false;
	return findWays(arr ,( totalSum - d)/2);
	
	
	
}


