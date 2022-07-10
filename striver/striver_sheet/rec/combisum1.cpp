class Solution {
public:
   void helper(vector<int>& candidates, int target ,vector<vector<int >>& ans,vector<int > &ds, int ind ){
        
        if(ind  == candidates.size()){
            if(target ==0 ){
                ans.push_back(ds);
            }
            return;
        }
        
        helper(candidates , target , ans, ds, ind +1 );
        if(candidates[ind]<= target){
            ds.push_back(candidates[ind]);
            helper(candidates, target - candidates[ind] , ans , ds , ind);
            ds.pop_back();
            
        }
        
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int >> ans;
        vector<int > ds; int  ind = 0;
        helper (candidates, target ,ans, ds, ind  );
        return ans;
    }
};