class Solution {
public:
   void dfs(int node, int parent, vector<int > &vis , vector<int >&tim , vector<int > &low ,vector<int> adj[], int timer ,vector<vector < int>> &ans){
        vis[node] = 1;
        tim[node] = low[node] = timer++;
       for(auto it : adj[node]){
           if(it == parent)continue ;
           if(!vis[it]){
               dfs(it, node, vis ,tim , low ,adj , timer, ans);
               low[node] = min(low[node], low[it]);
               if(low[it] > tim[node]){
                   vector<int> temp;
                   temp.push_back(it );
                   temp.push_back(node);
                   ans.push_back(temp);
               }
           }else{
               low[node] = min(low[node], low[it]);
           }
           
           
           
       }
       
       
       
       
       
       
   }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& a) {
        vector<int > adj[n]; int m=a.size();
        for(auto it : a){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        vector<vector < int>> ans;
        vector<int > tim(n ,-1 );
        vector<int > low(n , -1);
        vector<int > vis(n, 0);
        int timer = 0;
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i, -1, vis ,tim , low ,adj , timer, ans);
        }
        return ans;
    }
};