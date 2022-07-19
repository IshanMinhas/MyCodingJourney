#include<bits/stdc++.h>
#define ppi pair<int , pair<int , int >> 
int mazeRunner(int n, int m, vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    // Write your code here.
    priority_queue<ppi , vector<ppi> , greater<ppi>> pq;
    vector<int> distv(n*m+1 , 1e9 );
    distv[start[0] *m+ start[1]] = 0;
    pq.push({0 , {start[0], start[1]}});
    int dx[] = {0 , 0 , -1 , +1};
    int dy[] = {-1 , +1 , 0 , 0};
    while(!pq.empty()){
        int dist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++){
            int newx = x;
            int newy = y;int cnt=0;
        while(newx>=0 and newy>=0 and newx<n and newy<m and maze[newx][newy]==0){
            newx+=dx[i];
            newy+=dy[i];
            cnt++;
        }
            newx -=dx[i];
            newy-= dy[i];cnt--;
            if(dist +cnt < distv[newx*m + newy]){
                distv[newx*m +newy] = dist+cnt;
                pq.push({dist + cnt, {newx , newy}});
            }
        }     
    }
    if(distv[destination[0]*m + destination[1]]== 1e9){return -1;}
    else return distv[destination[0]*m + destination[1]];
}