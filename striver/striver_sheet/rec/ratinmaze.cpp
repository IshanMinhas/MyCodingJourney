int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void helper(vector<vector<int>>& maze,vector<vector<int>>& ans,vector<vector<int>>& matrix,int n,int i,int j){
    if(i==n-1 && j==n-1){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(matrix[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    
    for(int z=0;z<4;z++){
        int x=dx[z]+i,y=dy[z]+j;
        //  if possible
        if(x<0 || y<0 || x>=n || y>=n) continue;
        if(maze[x][y]!=0 && matrix[x][y]!=1){
            matrix[x][y]=1;
            helper(maze,ans,matrix,n,x,y);
            matrix[x][y]=0;
        }
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    if(n==0) return ans;
    
    vector<vector<int>> matrix(n,vector<int>(n,0));
    if(maze[0][0]==1) {
        matrix[0][0]=1;
        helper(maze,ans,matrix,n,0,0);
    }
    return ans;
}