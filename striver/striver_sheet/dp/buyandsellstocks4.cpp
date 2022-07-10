class Solution {
public:
    int maxProfit(int k, vector<int>& values) {
      
        int n = values.size();
       vector<vector<int>> ahead (2 ,vector< int > (k+1,0));
        vector<vector<int>>   cur(2 , vector<int > (k+1,0));   
        for(int i = n-1; i>= 0 ; i--){
            for(int j = 0; j< 2; j++){
                for(int z = 1; z< k+1; z++){
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
        
        
        
        
	    return ahead[1][k] ; 
 
    }
};