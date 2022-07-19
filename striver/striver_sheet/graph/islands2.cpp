#include<bits/stdc++.h>
class DSU{
private : 
        vector<int > parent , size;
 public : 
            DSU(int n){
            for(int i=0;i<n;i++){
                parent.push_back(i);
                size.push_back(1);
                
            }
        }
public : 
        int findULTParent(int node){
            if(parent[node]==node)return node;
            // path ccmpression tc= logn
            //path comp + size tc = 4*alpha as goof as constant
            return parent[node ] = findULTParent(parent[node]);
        }
public  :
        void Union(int u , int v){
            int pu = findULTParent(u);
            int pv = findULTParent(v);
            if(pu == pv){
                return;
            }
            if(size[pu] <size[pv] ){
                parent[pu] = pv;
                size[pv] += size[pv];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.
    DSU dsu(n*m+1); vector<int > ans;
    int cnt =0;
    vector<vector<int >> grid(n,  vector<int > (m, 0));
    int dx[] = {-1, +1 ,0 , 0};
    int dy[] = {0, 0, -1, +1 };
   
    for(auto it : q){
        int x = it[0];
        int y = it[1];
        if(grid[x][y]==1)continue;
        grid[x][y]=1;
        int ind = x*m + y;
        cnt++;
        for(int i=0;i<4;i++){
            int newx = x+ dx[i];
            int newy = y+dy[i];
            int ind2 = newx*m + newy;
            if(newx>=0  and newy>=0 and newx<n and newy<m and grid[newx][newy]==1 and dsu.findULTParent(ind)!=dsu.findULTParent(ind2)){
                cnt--;
                dsu.Union(ind , ind2);
            }
        }
        ans.push_back(cnt);
        
    }
   
    
    return ans;
}