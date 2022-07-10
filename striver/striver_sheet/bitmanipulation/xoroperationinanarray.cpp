class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int > anss(n , 0 );
        anss.push_back(start); int ans = start ; 
        for(int i=1; i< n; i++){
            anss[i] = start + 2*i;
            ans = ans^anss[i]; 
        }
        return ans;
    }
};