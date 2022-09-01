class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , j = 0;
        unordered_set<char > st;
        int cnt= 0 ;
        while(j < s.size() ){
           
            if(st.find(s[j] )== st.end()){    
                st.insert(s[j]); 
                cnt = max(cnt , j-i +1);
                j++;             
            }
            else{
                while(st.find(s[j])!= st.end()){
                    st.erase(s[i]);
                    i++;                
                }    
                st.insert(s[j]); 
                cnt = max(cnt , j-i +1);
                j++;
            }
         
        }
        return cnt;
        
    }
};