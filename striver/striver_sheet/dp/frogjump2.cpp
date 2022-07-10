#include<bits/stdc++.h>
// k jumps and not just 2 jumps like in the frog jump
int frogJump(int n, vector<int> &heights, int k)
{
    // Write your code here.
    vector<int > dp(n, 0);
    for(int i = 1; i<n ;i++){
       
        int ministeps = INT_MAX;
        for(int j = 1; j<=k; j++){
            
            if(i >j-1) int steps = dp[i-j] +abs(heights[i] - heights[i-j]); //or  i-j>=0
         
            ministeps = min(ministeps , steps);
        }

         dp[i] = ministeps;
    }
    
    return dp[n-1];
}