class Solution {
public:
    bool check(string &i , string &j){
        if(i.size() != j.size() +1 )return false;
        int l = 0 ; int k = 0 ;
        while(k < i.size()){
            if(i[k] == j[l] and l <j.size()) { l++; k++;}
            else{ k++; }
        }
        if(k == i.size() and l == j.size())return true;
        return false;
        
    }
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    
    
    int longestStrChain(vector<string>& words) {
       int n = words.size();
        vector<int  >dp( n, 1);
        int maxi = 1; 
        sort(words.begin(), words.end() , comp);
        for(int i = 0;i < n; i++){
            for(int j= 0 ;j < i; j++){
                if(check(words[i], words[j])and 1 + dp[j] > dp[i]){
                    dp[i] = dp[j]  + 1;
                }
                
                if(dp[i] > maxi)maxi = dp[i];
            }
            
        }
        return maxi;
        
        
        
        
    }
};