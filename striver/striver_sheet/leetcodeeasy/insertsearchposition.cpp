class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary seatch
        int low = 0 ; int high = nums.size() -1;
        while(high >= low){
            int mid = (low + high) >>1;
            if(target == nums[mid])return mid;
            if(target < nums[mid]){
                high = mid -1;
                
            }else{
                low = mid +1; 
            }
            
            
            
            
        }
        return low ;
    }
};