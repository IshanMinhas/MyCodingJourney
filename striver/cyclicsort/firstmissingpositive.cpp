class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //cyclic sort
        // check if element is between  0 and n and if it is at its position nums[i]- 1 in the arr
        for(int i=0; i<n; i++){
            while(nums[i] > 0 and nums[i] <=n  and nums[i]!= nums[nums[i]- 1]){
                swap(nums[i], nums[nums[i]- 1]);
            }
        }
        
        // now iterate and check which element is at diff pos
        for(int i=0 ;i<n ;i++){
            if(nums[i] != i + 1)return i+1;
        }
        return n+1;
    }
};