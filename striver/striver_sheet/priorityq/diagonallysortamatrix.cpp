class Solution {
public:
//map of pqs
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int , priority_queue<int , vector<int > , greater<int >>> mpp;
        for(int i = 0;i< mat.size(); i++){
            for(int j =0 ;j< mat[0].size(); j++){
               mpp[i-j].push(mat[i][j]);
            }
        }
        
        for(int i=0 ;i< mat.size();i++){
            for(int j = 0; j<mat[0].size(); j++){
                mat[i][j] = mpp[i-j].top() ;
                mpp[i-j].pop();
            }
        }
        return mat;
        
    }
};