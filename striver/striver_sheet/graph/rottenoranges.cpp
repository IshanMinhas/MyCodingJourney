class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); queue<pair<pair<int ,int > ,int> > q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== 2){
                   q.push({{i,j}, 0});
                    
                }
                if(grid[i][j]!=0){
                    cnt++;
                }
            }
        }
        int numb=0 ;int ans = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time =q.front().second;
            q.pop(); numb++; ans =max(ans, time);
            int dx[4] = {0 , 1 , -1 , 0};
            int dy[4] = {1 , 0, 0 , -1};
            for(int i=0; i<4; i++){
                int newx = x+ dx[i];
                int newy= y+dy[i];
                
                if(newx >=0 && newx <n &&  newy>=0 && newy <m && grid[newx][newy] == 1){                 grid[newx][newy] = 2;
                    q.push({{newx, newy}, time+1});
                }
            }
                     
        }
        
        
        if(numb == cnt){
                return ans ;
            } 
        
        
        
        return -1;
        
    }
};