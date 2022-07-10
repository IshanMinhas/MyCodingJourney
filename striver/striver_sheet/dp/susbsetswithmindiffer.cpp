// divide arr by 2 and bit mask
// if incdices can be -ve and 0

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2; 
        vector<int> left(nums.begin(), nums.begin()+n), right(nums.begin()+n, nums.begin()+2*n); 
        
        vector<vector<int>> vals(n+1); 
        for (int mask = 0; mask < (1<<n); ++mask) {
            int diff = 0, key = __builtin_popcount(mask); 
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? left[i] : -left[i]; 
            vals[key].push_back(diff); 
        }
        
        for (auto& v : vals) sort(v.begin(), v.end()); 
        
        int ans = INT_MAX; 
        for (int mask = 0; mask < (1<<n); ++mask) {
            int diff = 0, key = n - __builtin_popcount(mask); 
            for (int i = 0; i < n; ++i) 
                diff += (mask & (1 << i)) ? right[i] : -right[i]; 
            auto it = lower_bound(vals[key].begin(), vals[key].end(), -diff); 
            if (it != vals[key].begin()) ans = min(ans, abs(diff + *prev(it))); 
            if (it != vals[key].end()) ans = min(ans, abs(diff + *it)); 
        }
        return ans; 
    }
};

// if incideces are only +ve
//dp
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totSum = 0;
    for(int i = 0 ; i<n ; i++){
        totSum += arr[i]; 
    }
    int  k = totSum;

	vector<vector<bool>> dp(n, vector<bool>(k+1 , 0));
    for(int i = 0; i<n ; i++){
        dp[i][0] = true;
    }
	
    if(arr[0] <= k) {dp[0][arr[0]] = true;}
	
    for(int ind = 1 ; ind<n ; ind++){
        for(int target = 1 ; target<=k ;target++ ){
            bool noTake = dp[ind -1 ][target];
            bool take = false;
            if(arr[ind] <= target){
                take= dp[ind -1][target - arr[ind]];
                
        }
			dp[ind][target] = take or noTake;
    }}
		
		
		
    int mini = 1e9;
    for(int s1 = 0; s1 <= totSum/2 ; s1++){
        if(dp[n-1][s1] == true){
            mini = min(mini , abs((totSum -s1) - s1));
        }



    }

return mini;

}


