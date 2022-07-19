class Solution {
public:
    #define ppi  pair < int,int  >
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<ppi> adj[n+1];
        
        for(auto it : times){
           adj[it[0]].push_back({it[1], it[2]});
       }
        priority_queue<ppi ,vector<ppi> ,greater<ppi> > pq;
       vector<int > distV(n+1, 1e9);
        distV[k] = 0; 
        pq.push({0 ,k} );
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int newnode = it.first;
                int newdist = it.second;
                if(newdist + dist < distV[newnode]){
                    distV[newnode] = newdist +dist;
                    pq.push({newdist + dist , newnode});
                }
            }
        }
        
        int maxi = 0 ;
        for(int i=1; i<= n; i++){
           maxi = max(maxi , distV[i]); 
        }
        if(maxi==1e9)return -1;
        return maxi;
    }
};