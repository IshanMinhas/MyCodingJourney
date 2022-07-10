class Solution {
public:
   
long f(int ind, int buy, int cap , vector<int>& values,  vector<vector<vector<int>>> &dp){
	if(ind == values.size()){
		return 0;
	}
    if(cap == 0 )return 0;
	if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
	long profit = 0;
	if(buy){
		profit = max(-values[ind] + f(ind+1 , 0, cap ,  values,  dp), 0+f(ind +1 , 1,cap ,  values , dp));
	}
	else{
		profit = max(values[ind] + f(ind +1 ,1,cap -1, values , dp), 0+ f(ind+1 , 0,cap ,  values, dp));
	}
	return dp[ind][buy][cap] =  profit;
}




    int maxProfit(vector<int>& prices ) {
        int n = prices.size();
       vector<vector<vector< int >>> dp(n , vector<vector<int>>  (2 ,vector< int > (3,-1)));
	return f(0 , 1 , 2 , prices , dp); 
    }
};


class Solution {
public:
   int maxProfit(vector<int>& values ) {
        int n = values.size();
       vector<vector<int>> ahead (2 ,vector< int > (3,0));
        vector<vector<int>>   cur(2 , vector<int > (3,0));   
        for(int i = n-1; i>= 0 ; i--){
            for(int j = 0; j< 2; j++){
                for(int z = 1; z< 3; z++){
                    int profit = 0;
	                if(j){
		            profit = max(-values[i] + ahead[ 0][z], ahead[1][z]);
	                                    }
	                else{
		                profit = max(values[i] + ahead[1][z -1], ahead[0][z]);
	                    }
	               cur[j][z] =  profit;
                }
            }
            ahead = cur;
        }
        
        
        
        
	    return ahead[1][2] ; 
    }
};