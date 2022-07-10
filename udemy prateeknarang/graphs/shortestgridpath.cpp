#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int x;
    int y;
    int distance;
    Node(int x, int y , int distance){
        this-> x = x;
        this-> y = y;
        this-> distance = distance;
    }
};


class Compare{
    public:
    bool operator()(const Node &a , const Node &b){ // returns the smaller one first in set
        return a.distance <= b.distance;
    }
};


int shortestPath(vector< vector<int>> grid){

    // reeutnr the  shortest path len
    int m = grid.size(); // no of rows
    int n = grid[0].size(); // no of cols

    int i=0; 
    int j =0;
    vector< vector<int>> dist(m+1 , vector<int> (n+1 , INT_MAX)); // m+1 rows and each row has m+1 columns and dist as inf
    dist[i][j] = grid[0][0]; // dist of 1st is 31 and rest is inf
    set<Node , Compare> s ;
    s.insert(Node(0,0,dist[0][0]));
    int dx[] = {0 ,0 , 1 , -1 }; // can move in 4 dir only
    int dy[] = {1 , -1 , 0 ,0};
    while(!s.empty()){
        auto node  = s.begin();
        int currentx = node->x;
        int currenty = node->y;
        int currentdis = node->distance;
        s.erase(node);
        for(int k = 0 ; k<4 ; k++){
            int newx = currentx + dx[k];
            int newy = currenty + dy[k];
            
            if(newx >=0 and newx<m and newy >=0 and newy< n and (currentdis + grid[newx][newy]) < dist[newx][newy] ){
                Node temp(newx , newy , dist[newx][newy]);
                if(s.find(temp)!=s.end()){
                    s.erase(temp);
                }
                int newdis = currentdis + grid[newx][newy];
                dist[newx][newy] = newdis;
                s.insert(Node(newx , newy , newdis));

            }
        }
    }
    return dist[m-1][n-1];
}
int main(){

    vector< vector <int> > grid= { 
        { 31 ,100 , 65 , 12 , 18},
        { 10,  13, 47, 157,  6},
        {100 , 113 , 174 , 11, 33},
        {88 ,124 ,41 ,20 ,140},
         {99, 32 ,111 ,41, 20}} ;


    cout << shortestPath(grid) << endl;

}
