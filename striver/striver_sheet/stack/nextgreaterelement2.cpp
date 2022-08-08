class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int > st;
         int n = nums.size();
        vector<int > vec(n, -1);
       
        for(int i=2*n- 1;i>=0;i--){
            while(!st.empty() and st.top() <= nums[i%n]){
                st.pop();
            }
            
            if(!st.empty() and i<n){
                vec[i] = st.top();
                
            }
           
            st.push(nums[i%n]);
        }
        return vec;
    }
};