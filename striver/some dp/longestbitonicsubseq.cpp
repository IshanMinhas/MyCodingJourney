// inc then dec or inc only or dec only
#include<bits/stdc++.h>
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	   
	
	vector<int> dp1(n , 1);
	for(int i = 0; i<=n-1 ; i++){
		
		for(int prev =0 ; prev<= i-1 ; prev++){
			if(arr[prev]<arr[i] && 1+dp1[prev] > dp1[i]){
				dp1[i] = 1+dp1[prev];
				
			}
		}
	}
	
	vector<int> dp2(n , 1);
	for(int i = n-1; i>=0 ; i--){
		
		for(int prev = n-1 ; prev> i ; prev--){
			if(arr[prev]<arr[i] && 1+dp2[prev] > dp2[i]){
				dp2[i] = 1+dp2[prev];
				
			}
		}
	}
	int maxi = 0;
	for(int i = 0; i<n; i++){
		maxi = max(maxi , dp1[i] + dp2[i]-1);
	}
	
	return maxi;

} 
