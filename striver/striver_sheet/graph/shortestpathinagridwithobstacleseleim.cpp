class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row=grid.size(), col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,-1));
        queue<vector<int>> q;
        //x, y, current step, remaining k
        q.push({0,0,0,k});
        
        while(!q.empty()){
            int size = q.size();
            for(int loop=0;loop<size;++loop){
                int x = q.front()[0];
                int y = q.front()[1];
                int step = q.front()[2];
                int newk = q.front()[3];
                q.pop();
                
                //if we are at the bottom right cell then return no. of steps
                if(x==row-1 and y==col-1) return step;
                
                //check if current position is inside matrix or not
                if(x<0 or x>=row or y<0 or y>=col) continue; 
                
                // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
                if(vis[x][y]!=-1 and vis[x][y]>=newk) continue;
                
                // If we hit an obstacle & we don't have any Ks remaining, continue else If we still have Ks to spend, we will decrease k by 1 i.e newk--.
                if(grid[x][y]==1){
                    if(newk>0) newk--;
                    else continue;
                }
                
                // We store the currentRemaining K after spending K (if required) into the visited matrix.
                vis[x][y]=newk;
                
                //push all adjecent cell to the queue
                for(int i=0; i<4; ++i){
                    int x1 = x+dx[i], y1 = y+dy[i];
                    q.push({x1,y1,step+1,newk});
                }//end of inner for-loop
            }// end of for-loop
        }//end of while-loop
        return -1; //if no path found;
    }
};


class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<array<int , 3>> q;
        vector<vector<vector<int> >>dist (n , vector<vector<int > >(m ,vector<int > (k+1 , 1e9)));
        int steps = 0 ;
        q.push({0,0,0});
        dist[0][0][0] = 0 ;
        while(!q.empty()){
            array<int, 3> cur = q.front();
            q.pop();
            for(int i=0 ;i< 4; i++){
                array<int , 3 > next {cur[0] + dx[i] , cur[1] + dy[i] , cur[2]};
                if(next[0] >= 0 and next[1] >= 0 and next[0] <n and next[1] <m ){
                    if(grid[next[0]][next[1]] == 1){
                        next[2]++ ;
                    }
                    if(next[2] <= k ){
                        if(dist[next[0]][next[1]][next[2]] == 1e9){
                            q.push(next);
                            dist[next[0]][next[1]][next[2]] = dist[cur[0]][cur[1]][cur[2]] + 1 ;
                        }
                    }
                }
                
                
            }
        }
        
        int  ans = 1e9 ; 
        for(int i= 0; i<= k ; i++){
            ans = min(ans , dist[n-1][m-1][i]);
        }
        
        if(ans == 1e9)return -1;
        return ans;
    }
};