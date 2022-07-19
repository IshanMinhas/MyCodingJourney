class Solution {
public:
    int dx[4] = {0,0,-1,1}; int dy[4]={-1,1,0,0};
    void dfs(int i,int j,vector<vector<int>>& grid, int n ,int m){
        
        if(i<0 || i>n-1 || j<0 || j>m-1 || grid[i][j]!=1){
            return ;
        }
        if(grid[i][j]==1)grid[i][j]=2;
        for(int x=0;x<4;x++){
            dfs(i+ dx[x], j+dy[x] , grid , n , m);
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]== 1){
                    dfs(i,  j, grid, n , m);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){grid[i][j]=0;cnt++;}
                if(grid[i][j]==2)grid[i][j]=1;
            }
        }
        return cnt;
    }
};