#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int maximumProfit(vector<int> &prices){
    // Write your code here.
	int mini = prices[0];
	int maxProfit = 0;
	int n = prices.size();
	for(int i=1 ; i<n ; i++){
		int profit = prices[i] - mini;
		maxProfit = max(maxProfit , profit);
		mini = min(mini , prices[i]);
	}
	return maxProfit;
	
	
}

int maxprofit(vector<int> &prices ){
	int n = prices.size();
	int profit = 0;
	for(int i= 0 ; i< n-1; i++){
		if(prices[i+1] > prices[i]){
			profit += prices[i] - prices[i+1]; 
		}
	return sum;
	}









}