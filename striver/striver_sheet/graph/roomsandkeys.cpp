class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int > q;
        vector<int > vis(n , 0);
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : rooms[node]){
                if(vis[it]==0){
                   vis[it]=1 ;
                   q.push(it);
                }
            }
        }
        for(int i=0;i<rooms.size();i++){
            if(vis[i]==0)return false;
            
        }
        return true;
        
    }
};