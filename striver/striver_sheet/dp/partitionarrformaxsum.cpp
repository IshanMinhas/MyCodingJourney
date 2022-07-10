class Solution {
public:
    bool partitionpossible(int i ,int j , int k){
     if(j-i+1 <= k) return true;
	    else return false;
	
    }
    int f(int i, vector<int >&arr, int k , vector<int> &dp){
        if(i == arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi = -1e9; int ele = -1e9;
        for(int j= i; j< arr.size() ;j++){
            
            ele = max(ele , arr[j]);
            if(partitionpossible(i , j , k )){
               int cost =(j-i+1)*ele + f(j+1 ,arr, k , dp); 
                 maxi = max(cost, maxi);
            }
            
        }
       
        return dp[i] = maxi;
    } 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int >dp(arr.size(), -1);
        return f(0, arr,k ,dp);
    }
};