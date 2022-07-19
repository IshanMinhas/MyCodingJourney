class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(); int m= image[0].size();
        vector<int > vis(n*m, 0);
        int val = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int >> q;
        q.push({sr, sc});
        vis[sr*m+sc] = 1;
        int dx[]= {0,0,-1,1};
        int dy[] ={-1,1,0,0};
        while(!q.empty()){
            int x =q.front().first;
            int y= q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x+ dx[i];
                int newy= y +dy[i];
                if(newx>=0 and newy>=0 and newx<n and newy<m and image[newx][newy]== val and vis[newx* m + newy]==0){
                    image[newx][newy] = image[x][y];
                    vis[newx*m + newy]= 1;
                    q.push({newx , newy});
                    
                }
                
               
            }
             
            
        }
        
    return image;
        
        
    }
};