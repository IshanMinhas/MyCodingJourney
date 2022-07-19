class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        queue<pair <int , int >> dq; 
        vector<vector< int >> distv(n , vector<int> (m, INT_MAX));
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if(mat[i][j]==0){
                    distv[i][j]=0;
                    dq.push({i , j });
                }
            }
        }
        
        while(!dq.empty()){
            int verx = dq.front().first;int very = dq.front().second;
            
            dq.pop();
            for(int i=0;i<4;i++){
                auto x =verx + dx[i]; 
                auto y =very + dy[i];
                
                if(x>=0 and x<n and y>=0 and y<m){
                if(distv[verx][very] + mat[x][y] < distv[x][y]){
                    distv[x][y] = distv[verx][very] + mat[x][y];
                    dq.push({x,y});
                }}
            }
        }
        return distv;
    }
};