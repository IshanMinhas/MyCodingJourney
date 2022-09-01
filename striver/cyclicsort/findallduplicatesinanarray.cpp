class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //cyclic sort
        int i= 0 ; int n = nums.size();
        while(i < n){
            int correct= nums[i] - 1;
            if(nums[i] != nums[correct]){
                swap(nums[i] , nums[correct]);
            }else i++;
        }
        
        vector<int >ans;
        for(int i = 0 ;i <nums.size() ;i++)if(nums[i] - 1!=i )ans.push_back(nums[i]);
        return ans;

    }
};