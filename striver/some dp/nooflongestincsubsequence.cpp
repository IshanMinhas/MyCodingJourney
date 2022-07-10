#include<bits/stdc++.h>
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
	int n =arr.size();
	vector<int> dp(n , 1), cnt(n,1);
	
	int maxi = 1;
	
	for(int i = 0; i<=n-1 ; i++){
		
		for(int prev =0 ; prev<= i-1 ; prev++){
			if(arr[prev]  <arr[i] && 1+dp[prev] > dp[i]){
				dp[i] = 1+dp[prev];
				// inherit the count
				cnt[i] = cnt[prev];
				
			}
			else if(arr[prev ]< arr[i] and 1 + dp[prev] == dp[i]){
				cnt[i] += cnt[prev]; // inc the count
			
			}
		}
		maxi = max(maxi , dp[i]);
		
	}
	
	int nos = 0;
	for(int i = 0; i<n; i++ ){
		if(dp[i] == maxi){
			nos += cnt[i];
		}
	}
	
	return nos;
}
