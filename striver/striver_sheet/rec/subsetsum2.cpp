    void helper(vector<int>& candidates, vector<vector<int >>& ans,vector<int > &ds, int ind ){
        
        if(ind  == candidates.size()){
            auto it = std::find (ans.begin(),ans.end(), ds);
            if(it == ans.end()){
            ans.push_back(ds);}
            return;
        }
        
             helper(candidates ,  ans, ds, ind +1 );
        
            ds.push_back(candidates[ind]);
            helper(candidates, ans , ds , ind+1);
            ds.pop_back();    
           
    }
    
   
  vector < vector < int >> subsetsWithDup(vector < int > & candidates) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int >> ans;
        vector<int > ds; int  ind = 0;
        helper (candidates,ans, ds, ind  );
        return ans;
    }
};




  /*  void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index + 1, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    fun(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
    return ans;
  }*/