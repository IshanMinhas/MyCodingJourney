class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size() ; int n = haystack.size();
         int j = 0 ; 
        if(m ==0 )return 0;
        for(int i =0 ;i< n ; i++){
            if(needle[j] == haystack[i]){
                j++;
            }
            else if(needle[j]!=haystack[i]){
                i = i-j;
                j = 0 ;
                
            }
         if(j == m)return i-j+1;
            
            
            
            
            
            
            
        }
        return -1;
    }
};



class Solution {
public:
    int strStr(string b, string a) {
          if(b.find(a)<b.size())

       return b.find(a);

   else

       return -1;
            
    }
};0