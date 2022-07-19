class Solution {
public:int dx[4] = {0 , 1 , -1 , 0 };
            int dy[4] = {1 , 0, 0 , -1  };

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();queue <pair<int,int> > q;
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i, j });
                    
                }
            }
        }
        if(q.size() == n*m)return -1;
        
        int dist= 0 ;
        while(q.size()){
            int size = q.size();
            dist++;
            while(size--){
                int x = q.front().first;
                int y =q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newn = x+dx[i] ; int newm = y+dy[i];
                    if(newn>=0 && newn<n && newm>=0 && newm<m && grid[newn][newm]== 0){
                        grid[newn][newm] =1 ;
                        q.push({newn, newm});
                    }
                }
            }
            
        }
        
        
        return dist-1;