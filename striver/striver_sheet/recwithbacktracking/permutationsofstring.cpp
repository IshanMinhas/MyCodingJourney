#include<iostream>
#include< bits/stdc++.h>
using namespace std;

class Solution {
private:    
    void f(vector<int> &ds , int freq[] , vector<vector<int>> &ans , vector<int> &nums){
        if(ds.size()== nums.size()){
        ans.push_back(ds);
        return;
        }
        
        for(int i =0; i<=nums.size()-1; i++){
        
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                f(ds, freq , ans, nums);
                freq[i] = 0;
                ds.pop_back();
                }
        
        
        
    }
    
    
    
    }
       
    
    
    
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0; i<nums.size(); i++){
            freq[i] = 0;
        }
        vector<vector<int>> ans;
        f(ds , freq, ans, nums);
        return ans;
    }
};




//-------------------------------------------------------------------------------------------
//optimised _SPACE
void f1(int index , vector<vector<int>> &ans,   vector<int>& nums){
    if(index == nums.size() ){
        ans.push_back();
        return ;

    }



    for(int i = index; i<= nums.size() ; i++){
        swap(nums[index] , nums[i]);
        f1(ind + 1 , ans, nums);
        swap(nums[index] , nums[i]); // backtracking


    }


}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f1(0, ans, nums);
        return ans;
    }