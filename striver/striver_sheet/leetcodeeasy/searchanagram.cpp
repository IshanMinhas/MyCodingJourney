class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char , int > mp1 ; 
        map<char , int> mp2;
        if(s.size()!= t.size())return false;
        for(int i = 0 ;i<s.size(); i++){
            if(mp1.find(s[i]) == mp1.end()){
                mp1.insert(make_pair(s[i] , 1 ));
            }else{
                mp1[s[i]]++;
            }
            
            if(mp2.find(t[i]) == mp2.end()){
                mp2.insert(make_pair(t[i] , 1 ));
            }else{
                mp2[t[i]]++;
            }
                
        }
        
        if(mp1 == mp2)return true;
        
        return false;
        
        
        
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s==t) return true;
        if (s.size()!=t.size()) return false;
        unordered_map <char, int> umap;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto it: umap) {
            if (it.second) return false;
        }
        return true;
    }
};