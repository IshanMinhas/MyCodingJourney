#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector< int>> matrix , vector< vector< int>> &cache ,vector < vector< bool>> visited , int i , int j , int m , int n ){
    visited[i][j] =true;
    int cnt = 0;
    int dx[] = { 0 , 0 , 1 , -1};
    int dy[] = { 1 , -1 , 0 ,0};
    for(int k = 0 ; k<4 ; k++){

        int newx = i + dx[k];
        int newy = j + dy[k];

        if(newx >=0 and newy>=0 and newx<m and newy < n and matrix[i][j] < matrix [newx][newy]){
            int subprobcount = 0;
            if(visited[newx][newy]){
                cnt = max(cnt , 1 +cache[newx][newy]);
            }
            else{
                dfs(matrix , cache , visited , newx , newy, m , n);
                cnt = max(cnt, 1 +cache[newx][newy]);
            }
        }
    }

cache[i][j] = cnt;

    return;
}

int longestpathsequence( vector< vector< int>> matrix){


    int m = matrix.size();
    int n = matrix[0].size();

    vector< vector< int>> cache(m+1 , vector< int> (n+1 , 0));//acts as a DP
    vector < vector< bool>> visited( m+1 , vector <bool> (n+1 , false));
    int ans = 0;
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n; j++){
            dfs(matrix , cache ,visited , i , j , m, n);
            ans = max(ans , cache[i][j]);
        }
    }


    return ans +1;


}


int main(){


vector <vector <int>> matrix  = { };

cout << longestpathsequence(matrix) << endl;


}