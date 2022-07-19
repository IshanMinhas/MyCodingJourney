class Solution {
public:
    void dfs(int node , vector<int> &vis,vector<vector<int>>& a ){
        
        vis[node] = 1;
        for(int i=0;i<vis.size(); i++){
            if(!vis[i] and a[node][i] == 1 ){
                dfs(i ,vis, a);
            }
        }
       
    }
    
    
    
    int findCircleNum(vector<vector<int>>& a) {
        int n =a.size(); int m=a[0].size();
        int cnt = 0;
       
       
        vector<int> vis(n , 0);
        for(int i=0;i<n;i++){
            
                if(!vis[i]){
                    dfs(i ,vis, a);
                    cnt++;
                }
                
            
        }
        return cnt;
    }
};