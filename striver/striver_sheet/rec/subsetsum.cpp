void helper(vector<int > &num , vector<int> &ans, int sum , int ind){
    if(ind == num.size()){
        ans.push_back(sum);
        return;
    }
    
    
    helper(num , ans ,sum , ind+1);
    helper(num , ans , sum + num[ind], ind +1 );


}


vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int > ans;
    int ind = 0;
    int sum = 0;
    helper(num , ans, sum , ind);
    sort(ans.begin() , ans.end());
    return ans;
    
    
    
}