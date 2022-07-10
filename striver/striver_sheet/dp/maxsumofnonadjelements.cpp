#include<bits/stdc++.h>
int f(int n , vector<int > &nums, vector<int >&dp){
    if(n < 0)return 0;
    if(n == 0)return nums[n];
    if(dp[n]!= -1)return dp[n];
    int pick = nums[n] + f(n-2, nums,dp);
    int notpick = f(n-1, nums,dp);
    int maxi = INT_MIN;
    maxi = max(pick , notpick);
    return dp[n] = maxi;
  
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size(); vector<int > dp(n +1, -1);
    return f(n -1, nums, dp);
}





#include<bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size(); //vector<int > dp(n , 0);
    if(n < 0)return 0;
    int prev = nums[0] , prev2 = 0;
    
   
    for(int i = 1; i<n; i++){
        int pick = nums[i] + prev2;
        int notpick = prev;
        int maxi = INT_MIN;
        maxi = max(pick , notpick);
        int curi = maxi;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}