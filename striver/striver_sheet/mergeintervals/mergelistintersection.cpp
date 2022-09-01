class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int > >ans;
        int i = 0, j =0; 
        while(i < f.size() and j<s.size()){
            int mini = max(f[i][0] , s[j][0]);
            int maxi = min(f[i][1] , s[j][1]);
            if(mini <= maxi )ans.push_back({mini , maxi});
            if(f[i][1] < s[j][1] )i++;
            else j++;
            
            
        }
        /*for(int i = 0;i < f.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(f[i][0] <= s[j][1] and f[i][1] >= s[j][0] ){
                    int mini = max(f[i][0] , s[j][0]);
                    int maxi = min(f[i][1] , s[j][1]);
                    ans.push_back({mini , maxi});
                }
            }
        }*/
     return ans;   
    }
};