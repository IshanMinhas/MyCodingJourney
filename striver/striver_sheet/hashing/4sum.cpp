class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<= n-1 ; i++){
            for(int j = i+1 ; j<=n-1 ; j++){
                int left = j+1 ;
                int right = n-1 ;
                int target2 = target - nums[i] - nums[j];
                while(left < right){
                    int sumLR = nums[left] + nums[right];
                    if(sumLR < target2) left++;
                    else if(sumLR > target2) right--;
                    else{
                        vector<int> quad(4,0) ; 
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        while(left < right && nums[left] == quad[2]) ++left;
                        while(left < right && nums[right]== quad[3]) --right;
                    }
                }
                while(j+1 < n  && nums[j+1] == nums[j]) ++j;
            }
            while(i+1 < n  && nums[i+1] == nums[i]) ++i;
        }
     return res;
    }
    
};