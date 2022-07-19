class Solution {
public:
    #define pi pair<long ,long > 
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long >ways(n , 0); int mod = 1e9+7; 
        vector<long > distv(n , LONG_MAX);
        vector<pair<long , long >> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[2] ,it[1]}); 
            adj[it[1]].push_back({it[2] ,it[0]}); // dist , adj
        }
        distv[0]= 0; ways[0] = 1;
        priority_queue<pi , vector<pi> , greater<pi > > pq;
        pq.push({ 0 ,0 }); // dist , adj
        while(!pq.empty()){
            long time = pq.top().first;
            long node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                long ti = it.first; // time
                long i = it.second; // adj node
                if(ti + time < distv[i]){
                    distv[i] = ti + time; ways[i]= ways[node];
                    pq.push({ti + time,i });
                }
                else if(ti + time == distv[i]){
                    ways[i]= (ways[i] + ways[node])%mod;
                }
            }
        }
        
        
        
        return ways[n-1];
    }
};