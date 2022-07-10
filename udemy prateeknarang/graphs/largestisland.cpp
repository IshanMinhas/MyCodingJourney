#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 

int dfs(vector< vector<bool>>  &visited , vector< vector<int>> &matrix , int i , int j , int n , int m){
    visited[i][j] = true;
    int cs =1;
    int dx[] = { 0 , 0 , 1 , -1};
    int dy[] = { 1 , -1 , 0 , 0};
    for(int k = 0; k<4; k++){
        int newx = i + dx[k];
        int newy = j + dy[k];
        
        
        if(newx >=0 and newy>=0 and newx <m and newy<n and !visited[newx][newy] and matrix[newx][newy] == 1){
            int subcomponent = dfs(visited , matrix , newx , newy , n , m);
            cs += subcomponent;
        }
    }
    return cs;
}




int largestisland(vector < vector< int> > matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector< vector<bool>> visited(m, vector<bool>(n,false));
    int largest = 0;

    for(int i =0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            if(!visited[i][j] and matrix[i][j] == 1){
                int size = dfs(visited , matrix, i , j , n , m);
                if(size> largest){
                    largest = size;

                }
            }
        }
    }
    return largest;
}    



int main(){

    vector< vector<int>> grid = { 
            {1, 0,0, 1, 0},
            {1, 0 ,1, 0, 0},
            {0,0,1,0,1},
            {1,0,1,1,1},
            {1,0,1,1,0}};

    cout << largestisland(grid)<< endl;

}