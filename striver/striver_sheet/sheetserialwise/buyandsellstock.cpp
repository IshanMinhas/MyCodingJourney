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