class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
	    vector<vector<int >> ans;
        int n = nums.size();
        sort(nums.begin() , nums.end()); // sorting so we dont have to use set while inserting vector temp
        for(int i=0 ;i< n -2; i++){ // dont need to go till end
            if(i == 0 || (i > 0 && nums[i] != nums[i-1 ])){ // removing duplicates i i.e if same i then we skip that index
                
                int l = i+1 ; int h = n- 1, target = -nums[i]; // two pointers with target as a[l] + a[h] = 0 - a[i]
                while(h > l){
                    if(nums[l] + nums[h]== target){
                        vector<int > temp; 
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        while(h > l and nums[l] ==nums[l +1 ])l++; // to prevent duplicates
                        while(h > l and nums[h] ==nums[h-1 ])h--;// '' 
                        l++ ; h--; // we got to move both pointers cuz we don't want duplicates and if we move only pointer then we bound to find duplicates
                    }
                    else if(nums[l] + nums[h] < target){
                        l++; // if sum of l and h is less than target then move l forward cuz the arr is sorted and  opp fo more than cond
                    }else{
                        h--;
                    }
                }               
            }
        }
        return ans;
       
    }
};