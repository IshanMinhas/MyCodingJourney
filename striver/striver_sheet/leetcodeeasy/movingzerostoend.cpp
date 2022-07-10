class Solution {
public:
    #include<bits/stdc++.h>
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i<nums.size(); i++){
           if(nums[i])swap(nums[i], nums[count ++ ]);
        }
       
        
    }
};


void moveZeroes(vector<int>& nums)
{
    stable_partition(rbegin(nums),rend(nums),logical_not<int>());
}