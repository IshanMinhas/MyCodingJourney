void helper(int index , int k , int target , vector<int > &arr , vector<vector<int >>& ans , vector<int >& ds ){
         if (target == 0) {
             if(ds.size() == k)ans.push_back(ds);
        return;
  }
    for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            helper(i + 1,k ,  target - arr[i], arr, ans, ds);
            ds.pop_back();    
}    
}
    
    
vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int >> ans;
        vector<int > ds;
       vector<int> arr = {1,2,3,4,5,6,7,8,9} ;
       
        helper(0 , k , n , arr ,  ans , ds );
            
    return ans;
    
    
    
    }
    