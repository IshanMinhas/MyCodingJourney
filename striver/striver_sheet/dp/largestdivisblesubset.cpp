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
/*
sort();

int f(){
    vector<int> dp(n), hash(n);
    int last = 0;
    for(int i = 0;i < n ;i++){
        hash[i] = i;
        for(int j = 0 ; j < i; j++){
            if(nums[i]%nums[j]== 0){
                if(1+dp[j] > dp[i]){
                    dp[i] = 1+dp[i]; 
                };
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            last = i ;
        }
 
    }

    int i = find(vec.begin , veec.end , maxi );
    ans.push_back(nums[lasti]);
    while(lasti){
        lasti = hash[lasti];
        nums.push_back(nums[lasti]);
    }
*/
}