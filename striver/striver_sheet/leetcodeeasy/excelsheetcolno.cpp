class Solution {
public:
    int titleToNumber(string s) {
        int ans= 0 ; int n = s.size();
        for(int i = n-1; i>=0 ;i--){
            ans += (int(s[i]) - 64 )* pow(26 , n-i -1) ;
        }
        return ans;
    }
};