
class Solution {
  public:
          int dx[4] ={-1 ,0 ,1,0};
          int dy[4] ={0, -1 ,0 ,1};
   
    void dfs(int x , int y , vector<vector<int >> &grid , vector< int >  &vis ,vector<pair < int, int  >> &ans , int row, int col ){
          
        
           int n = grid.size();
        int m = grid[0].size();
            vis[x* m + y] = 1 ; 
          
        ans.push_back({x - row , y - col});
        for(int i=0 ;i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 and newy >= 0 and newx < n and newy < m and vis[newx * m + newy]== 0 and grid[newx][newy]== 1 ){
                dfs(newx ,newy , grid , vis , ans , row , col);
            }
        }
        
            
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair < int ,int >> > sett;
        vector< int > vis(n *m , 0 );
     
        for( int i = 0 ;i < n; i++){
            for(int j = 0; j< m; j++){
                if(!vis[i *m +  j] and grid[i][j] == 1 ){
                    vector<pair<int , int > > ans;
                    dfs(i , j ,grid , vis , ans, i , j);
                    sett.insert(ans);
                }
            }
        }
        return sett.size();
    }
};