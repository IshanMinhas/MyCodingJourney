class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map <int , int> indices;
        for(int i = 0  ; i< nums.size() ; i++){
            if(indices.find(target - nums[i]) != indices.end()){
                ans.push_back(indices[target - nums[i]]);
                ans.push_back(i);
         
            }
            indices[nums[i]] = i;
                
        }
        return ans;
        
        
        
        
        
    }
};