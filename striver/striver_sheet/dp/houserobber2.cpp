//https://leetcode.com/problems/house-robber/


#include<bits/stdc++.h>
long long int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size(); //vector<int > dp(n , 0);
    if(n < 0)return 0;
    long long int prev = nums[0] , prev2 = 0;
    
   
    for(int i = 1; i<n; i++){
        long long int pick = nums[i] + prev2;
        long long int notpick = prev;
        long long int maxi = INT_MIN;
        maxi = max(pick , notpick);
        long long int curi = maxi;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
    
   
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n =valueInHouse.size();
        vector<int> temp1, temp2;
        if(n==1)return valueInHouse[0];
        for(int i = 0; i<n ;i++){
          if(i!=0 ) temp1.push_back(valueInHouse[i]); 
          if(i!= n-1) temp2.push_back(valueInHouse[i]); 
            
            
        }
        
        
        
        
        return max(maximumNonAdjacentSum(temp1) , maximumNonAdjacentSum(temp2));
}