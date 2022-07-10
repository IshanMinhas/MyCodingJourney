class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        vector<int > res; int n = nums.size();
        priority_queue<pair<int , int >> maxh;
        for(int i=0 ;i< n ;i++){
            maxh.push({ abs(nums[i]- x), nums[i]});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()){
            
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        //reverse(res.begin(), res.end());
        
        sort(res.begin(),res.end());
        return res;
    }
};