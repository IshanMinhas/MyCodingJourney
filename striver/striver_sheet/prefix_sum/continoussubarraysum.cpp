class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // prefix sum
        vector<int > prefix_sum (nums.size());
        int running_sum = 0 ; int cnt  = 0 ;
        for(int i=0 ; i<nums.size(); i++){
            running_sum +=nums[i];
            running_sum %= k ;
            prefix_sum[i] = running_sum ;
            
        }
        unordered_set<int > st;
        
        for(int i = 0 ; i<nums.size(); i++){
            if(st.find(prefix_sum[i])!= st.end()){
                return true;
            }
            if(i==0 )st.insert(0);
            else st.insert(prefix_sum[i- 1]);
            
            
        }
        return false;
        
        
        
        
    }
};