#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int > dp(n, 0);
    for(int i = 1; i<n ;i++){
        int left = dp[i - 1] + abs(heights[i] - heights[i-1]) ; 
        int right = INT_MAX;
        if(i >1)  right = dp[i-2] +abs(heights[i] - heights[i-2]);
         dp[i] = min(left , right);
    }
    
    return dp[n-1];
}