class Solution {
public:
  
    int wiggleMaxLength(vector<int>& nums) {
       int n = nums.size();
        int posi = 1, nega = 1 ;
        if (n <= 1)return n;
        for(int  i= 1;i<n ;i++){
            if(nums[i] > nums[i-1])posi = nega +1 ;
            if(nums[i] < nums[i-1])nega = posi +1 ;
        }
        return max(posi , nega); 
    }
};
// can also be solved thru dp
