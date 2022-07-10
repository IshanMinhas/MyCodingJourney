class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size() ;
        vector<int > dp (n ,1 ) , hash(n );
        int maxi = 1 ;
        int lastI = 0;
        sort(nums.begin(), nums.end());
        for(int i= 0 ;i< n; i++){
            hash[i] = i;
            for(int j= 0 ;j<= i -1; j++){
                if(nums[i]%nums[j]== 0 and 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j ; 
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastI = i;
            }
        
        } 
        vector<int> temp;
	    temp.push_back(nums[lastI]);
	    while(hash[lastI] != lastI){
		    lastI = hash[lastI];
		    temp.push_back(nums[lastI]);
	    }

	
	return temp;
    }
};