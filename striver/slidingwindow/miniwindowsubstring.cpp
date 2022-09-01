class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())return "";
        int i  =0, j = 0 ;
        unordered_map<char, int > mpp;
        for(auto x : t)mpp[x]++;
        int count = mpp.size();
        int mini = 1e9;
        int start = 0 ;
        while(j < s.size()){
        
                 mpp[s[j]]--;
                if(mpp[s[j]]== 0 )count--;
                
                if(count == 0 ){
                while(count == 0){
                      if(mini > j-i +1 )mini = j-i+1 , start = i;
                    if(mpp.find(s[i]) != mpp.end()){
                        mpp[s[i]]++;
                    }
                    if(mpp[s[i]] > 0 )count++; 
                    i++;   
                 }
                }
             
                j++;       
         
        }
       if(mini == 1e9)return "";
        
        return s.substr(start , mini);
        
    }
};