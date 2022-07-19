class Solution {
public:
     bool dfs(int node , int color ,vector<vector<int>>& dislikes, vector<int> &col){
        col[node] = color;
        for(auto it : dislikes[node]){
            if(col[it]==-1){
                if(!dfs(it , !color, dislikes,col))return false;
            }
            else if(col[it]==color)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& dislikes) {
        
        int n = dislikes.size();
        vector<int> col( n, -1 );
       
        for(int i=0;i<n;i++){
            if(col[i] == -1){ 
                if(!dfs(i , 1 , dislikes, col))return false;
            }
        }
        return true;

    }
};