class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int diff1= -1e9; int diff2 = -1e9;
        for(int i =1; i<horizontalCuts.size(); i++ ){
            int j = i-1;
            diff1 = max(diff1,horizontalCuts[i]- horizontalCuts[j] );
        } 
         for(int i =1; i<verticalCuts.size(); i++ ){
            int j = i-1;
            diff2 = max(diff2,verticalCuts[i]- verticalCuts[j] );
        } 
        return (1LL*diff1*diff2)%MOD;
    }
};