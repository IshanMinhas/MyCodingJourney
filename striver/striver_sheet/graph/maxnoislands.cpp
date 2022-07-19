class Solution {
public:
    
    int dx[4]={-1,1,0,0}; int dy[4]={0,0,-1,1};
    void dfs(int x,int y ,vector<int >&vis , vector<vector<int>>& grid, int &cnt){
        vis[x*grid[0].size()+ y]=1;
        
        for(int i=0;i<4;i++){
            int newx = x+ dx[i]; int newy= y+dy[i];
            if(newx>=0 and newy>=0 and newx<grid.size() and newy<grid[0].size() and vis[newx*grid[0].size() + newy]==0 and grid[newx][newy]==1){
                cnt++;
                dfs(newx , newy , vis, grid, cnt);
                
                
            }
           
        }
         
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi =0;
        int n=grid.size(); int m=grid[0].size();
        vector<int >vis(n*m , 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur = 0;
                if(!vis[i*m + j] and grid[i][j]==1){
                    cur = 1;
                    dfs(i ,j ,vis , grid, cur);
                    
                }
                maxi = max(cur , maxi);
            }
        }
        
        return maxi;
    }
};



class Solution {
public:
    
    int dfs(vector<vector<int>>&grid , int row , int col)
    {
        if(row < 0 || row == grid.size() || col < 0 || col == grid[row].size() || grid[row][col] == 0)  return 0 ; 
        
        grid[row][col] = 0 ; 
        
        return (1 + dfs(grid , row + 1 , col) + dfs(grid , row - 1 , col) + dfs(grid , row , col + 1) + dfs(grid , row , col - 1)) ; 
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        int count = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1) 
                { 
                    count = max(count , dfs(grid , i , j)) ; 
                }
            }
        }
        return count ; 
    }
};