bool fnc(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	if(target ==0){
		return true;
	}
	if(ind == 0){
		return arr[0] == target;
	}
	if(dp[ind][target] != -1){
		return dp[ind][target];
	}
	bool notTake = fnc(ind -1 , target , arr, dp);
	bool take = false;
	if( arr[ind] <= target){
	take = fnc(ind -1 , target- arr[ind] , arr, dp);
	}
	return dp[ind][target] =  take or notTake;



}



bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<vector<int>> dp(n , vector<int> (k+1 , -1));
	return fnc(n-1 , k , arr, dp);
}

bool fnc(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
	if(target ==0){
		return true;
	}
	if(ind == 0){
		return arr[0] == target;
	}
	if(dp[ind][target] != -1){
		return dp[ind][target];
	}
	bool notTake = fnc(ind -1 , target , arr, dp);
	bool take = false;
	if( arr[ind] <= target){
	take = fnc(ind -1 , target- arr[ind] , arr, dp);
	}
	return dp[ind][target] =  take or notTake;



}



bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.
	vector<vector<bool>> dp(n , vector<bool> (target+1 , 0));
    
    for(int i = 0 ; i<n ;i++)dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int i = 1;i<n ;i++){
        for(int j =1 ;j<= target; j++ ){
                bool notTake = dp[i -1][ j ];
                bool take = false;
                if( arr[i] <= j){
                    take = dp[i-1 ][ j- arr[i] ];
                    }
                dp[i][j] =  take or notTake;
        }
    }
	
    
    return dp[n-1][ target];
}