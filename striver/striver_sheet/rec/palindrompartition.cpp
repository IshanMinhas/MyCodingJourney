class Solution {
public:
    
    bool check(string &s , int ind, int i){
         while(ind <= i ) 
             if(s[ind++] != s[i--])return false ;
        return true;
    }
    
    
    void helper(string &s, vector<vector<string >> &ans , vector<string > &ds, int index ){
        if(index == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i =index ; i< s.length() ; i++){
            if(check(s, index, i)){
                ds.push_back(s.substr(index ,  i - index +1 ));
                helper(s ,ans, ds ,i + 1);
                ds.pop_back();
            }            
        }           
   }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string >> ans;
        vector<string> ds;
        int index = 0;
        helper(s , ans , ds , index);
        return ans;
    }
};