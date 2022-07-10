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