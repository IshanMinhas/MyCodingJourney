
// BOYRE MOORE
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int > ans;
        int c1 = -1 , c2 = -1 , cc1 = 0 , cc2 = 0;
        for(int i = 0 ;i<nums.size(); i++){
            if(c1 == nums[i])cc1++;
            else if(c2 == nums[i])cc2++;
            else if(cc1 == 0 ){c1 = nums[i]; cc1++;}
            else if(cc2 == 0 ){c2 = nums[i]; cc2++;}
            else{
                cc1 -- ; cc2 --; }}
        
        cc1 =0 ; cc2 = 0;
            for(int i= 0 ;i< nums.size(); i++){
                if(c1 == nums[i])cc1++;
                else if(c2 == nums[i])cc2++;
            }
        
        if(cc1 >nums.size()/3)ans.push_back(c1);
        if(cc2 > nums.size()/3)ans.push_back(c2);
        return ans;
        
    }
};