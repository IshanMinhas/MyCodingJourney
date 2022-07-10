#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
	vector<int> dp(n , 1), hash(n);
	int maxi = 1;
	int lastindex = 0;
	for(int i = 0; i<=n-1 ; i++){
		hash[i] = i;
		for(int prev =0 ; prev<= i-1 ; prev++){
			if(arr[prev]<arr[i] && 1+dp[prev] > dp[i]){
				dp[i] = 1+dp[prev];
				hash[i] = prev ;
			}
		}
		
		if(dp[i] > maxi){
			maxi = dp[i];
			lastindex = i;
		}
	}
	vector<int> temp;
	temp.push_back(arr[lastindex]);
	while(hash[lastindex] != lastindex){
		lastindex = hash[lastindex];
		temp.push_back(arr[lastindex]);
	}
	reverse(temp.begin(), temp.end());
	for(auto x: temp){
		cout << x << "";
	}
	cout << endl;
	return maxi;
}
