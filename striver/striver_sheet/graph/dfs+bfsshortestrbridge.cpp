class Solution {
public:
    int m; int n ; 
    int dx[4] = {1,-1,0,0}; 
    int dy[4] = {0,0,-1,1};
    queue<pair <int , int >> q;
    // dfs to find the first island
    void dfs(int i , int j ,vector<vector<int >> &grid){
        if( i < 0 or j <0 or i >=n or j >= m or grid[i][j] ==2 or grid[i][j]== 0)return;
        
        grid[i][j] = 2;
        
        q.push({i , j});
        
        for(int k = 0 ;k < 4; k++){
            dfs(i + dx[k] , j+dy[k] , grid);
        }       
    }
    
    // multisource bfs to find the shortest level
    int bfs(vector<vector<int >> &grid){
        int s= 0;  // s == levels of bfs
        int st = INT_MAX;   // shortest level
        
        while(!q.empty()){
            int x= q.size();  
            while(x--> 0){
               auto temp = q.front();
                q.pop();
                for(int i=0 ; i< 4; i++){
                    int x = temp.first + dx[i] , y= temp.second  + dy[i];
                    if(x >= 0 and x < n and y >= 0 and  y<m and grid[x][y] == 1 ){
                        st = min(st , s);
                    }
                    if(x >= 0 and x < n and y >= 0 and  y<m and grid[x][y] == 0){
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
            s++;
        }
        return st;
    
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid[0].size(); n = grid.size(); int flag = 0 ;
        for(int i = 0 ;i< n;i++){
            for(int j = 0;j< m ;j++){
                if(grid[i][j]==1 and flag ==0){
                    // only want dfs for 1 island i.e only want 1 island in q
                    dfs(i , j , grid);
                    flag = 1;
                    break;
                }           
            }
        }
   
        return bfs(grid);
    }
};