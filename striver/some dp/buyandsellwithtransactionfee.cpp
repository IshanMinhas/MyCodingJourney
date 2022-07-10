int maximumProfit(int n, int fee, vector<int> &prices) {

	
	vector<int> cur(2 , 0);
	vector<int> after1(2 , 0); 
	 
	for(int ind = n-1 ; ind >= 0 ; ind--){
			
		cur[1] = max(- prices[ind] + after1[ 0] , 0 + after1[ 1] );		
			
		cur[0] = max(prices[ind] - fee + after1[ 1 ], 0+ after1[0 ]);
			
		
		after1 = cur;
		
	}
	return cur[ 1 ];    

}