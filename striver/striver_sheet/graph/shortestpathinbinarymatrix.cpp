class Solution {
public:
    #define ppi pair<int , pair<int ,int >> 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue< ppi , vector<ppi> , greater<ppi >  > q ;
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] !=0 ||  grid[n-1][m-1] !=0)return -1; 
        vector<int > distV(n*m , 1e9);
        distV[0] = 1;
        q.push({1 , {0,0  }});
        int dx[8] = { 0,0,-1,1, 1, 1, -1 , -1  }; int dy[8] = {-1,1 , 0, 0,-1, 1, -1, 1  };
        
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;
            int dist= q.top().first;   
            
             if(x == n-1 and y == m-1 )return distV[x*m + y];
            q.pop();
            
            for(int i=0;i<=7;i++){
                int newx = x +dx[i] ; 
                int newy = y+dy[i]; 
                int newdist = dist + 1;
               
                if(newx >= 0 && newy >= 0 && newx < n && newy <m && grid[newx][newy]==0 ){
                    if(dist + 1  < distV[newx*m + newy]){
                        distV[newx* m + newy] = dist +1 ;
                        q.push({dist +1  ,{ newx , newy} });
                        }
                }
            }
        }
       return -1;
        
    }
};