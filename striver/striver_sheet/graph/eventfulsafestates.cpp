class Solution {
public:
   bool checkCycle(int node, vector <vector< int >> &adj, int vis[], int dfsVis[], vector<bool > &ans) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
            if(!checkCycle(it, adj, vis, dfsVis, ans))return ans[node]= false;
        } else if (dfsVis[it] == 1 and vis[it]== 1 ) {
          return ans[node] = false;
        }
      }
      dfsVis[node] = 0;
      return ans[node];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int N = graph.size();
      int vis[N], dfsVis[N];
      memset(vis, 0, sizeof vis);
      memset(dfsVis, 0, sizeof dfsVis);
      vector<bool > ans(N , true);
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
           
          checkCycle(i, graph, vis, dfsVis, ans) ;
            
          }
        }
      
      vector<int > res;
        for(int i=0;i<N;i++){
            if(ans[i]==true)res.push_back(i);
        }
        return res;
    }
};