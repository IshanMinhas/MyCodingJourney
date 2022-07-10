class Solution {
public:
    bool check(bitset<26> string1, bitset<26>string2){
        for(int i=0;i<26; i++){
        if((string1[i] && string2[i] )== 1 )return false; 
            }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int maxi = 0 ;
        vector<bitset <26>> mpp(n);
        for(int i = 0; i< n ;i++ ){
            
            for(auto c : words[i]){
                mpp[i][c- 'a'] =1 ;
            }
            for(int j = 0 ;j < i; j++){
                if(check(mpp[i] , mpp[j])){
                    maxi=max(maxi ,(int)words[j].size()*(int)words[i].size()); 
                }
                }
            }
        return maxi;
    }
};