class Solution {
public:
    #define ppi pair < int , pair<int , int > > 
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue< ppi , vector<ppi> , greater<ppi >  > q ; // min pq
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int > distV(n*m , 1e9);                            // maintain min diff arr
        distV[0] = 0;                                                           
        q.push({0 , {0,0  }});
        int dx[4] = { 0,0,-1,1 }; int dy[4] = {-1,1 , 0, 0 };
        
        
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;
            int dist= q.top().first;   
            
             if(x == n-1 and y == m-1 )return distV[x*m + y];
            q.pop();
            
            for(int i=0;i<=3;i++){
                int newx = x +dx[i] ; 
                int newy = y+dy[i];          
                if(newx >= 0 && newy >= 0 && newx < n && newy <m){
                    int newdist = max(dist , abs(grid[x][y] - grid[newx][newy])); // max diff between two cells in path till newx, newy cell
                    if(newdist   < distV[newx*m + newy]){
                        distV[newx* m + newy] = newdist ; // update if you find path with lesser max diff between two cells till newx,newy cell
                        q.push({newdist   ,{ newx , newy} });
                        }
                }
            }
        }
       return 0;
        
    }
};