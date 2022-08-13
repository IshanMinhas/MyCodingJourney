class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string >> ans;
        int n = strs.size();
       unordered_map<string  , vector<string > > mpp;
        for(string str : strs){
            string t = str;
            sort(t.begin(), t.end());
            mpp[t].push_back(str);
            
        }
        for(pair < string , vector<string> > it : mpp){
            ans.push_back(it.second);
        }
       return ans;
        
    }
};