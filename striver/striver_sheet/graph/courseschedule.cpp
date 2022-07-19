//cycle
class Solution {
public:
    bool f(int i, vector<int> &vis,  vector<int> &pathvis , vector<int > adj[]){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto it : adj[i]){
            if(vis[it]==0){
                if(f(it ,vis, pathvis, adj))return true;
            }
            else if( pathvis[it]==1){
                return true;
            }
        }
        pathvis[i]=0;
        return false;
        
        
    }
    
    
    
    
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> vis(n , 0); vector<int >pathVis(n, 0);
        vector<int > adj[n];
        for(auto i : a){
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 if(f(i,vis, pathVis , adj))return false;
            }
        }
        return true;
        
        
        
    }
};