#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int f(int i, int prev, vector<int > &nums ,vector< vector<int >> &dp ){
       if(i == nums.size())return 0;
       if(dp[i][prev +1 ] != -1 )return dp[i][prev+1 ];
       int len =  0 + f(i+1 , prev, nums , dp);
       if(prev == -1 or nums[i] > nums[prev]){
           len = max(len ,  1 + f(i +1 , i , nums, dp) );
       }
       return dp[i][prev +1 ] = len;
       
   }
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
        vector< vector<int >> dp(nums.size() + 1 , vector<int > (nums.size() +1 , 0));
        
        for(int i= n- 1; i>= 0  ; i--
        ){
            for(int prev = i-1 ;prev >= -1  ; prev --){
                    int len =  0 + dp[i+1][prev+1 ];
                    if(prev == -1 or nums[i] > nums[prev]){
                    len = max(len ,  1 + dp[i +1] [i+1]  );
                            }
                    dp[i][prev +1 ] = len;
            }
        }
        return  dp[0 ][0 ];
    }
};


// binary search
class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size(); 
        vector<int > temp ;
        temp.push_back(nums[0]);
        int len = 1 ;
        for(int i= 1 ;i < n ;i++){
            if(nums[i ]  >temp.back()){
                temp.push_back(nums[i]); len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};





int f(int arr[] , int n ){
    vector<vector<int > > dp(n , vector<int > (n +1 , 0 ));
    for(int i = n-1 ; i>= 0; i--){
        for(int j = i -1 ; j >= -1  ; j--){
            int len =  0 + dp[i+1][j +1 ];
            if(j == -1 or arr[i] > arr[j]){
                len = max(len ,  1 + dp[i +1][i +1 ] );
            }
            dp[i][j +1 ] = len;
        }
    }
    return dp[0][0];
}