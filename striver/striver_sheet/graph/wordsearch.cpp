class Solution {
public:
    int dx[4] = {0,0,-1,1}; int dy[4] = {-1,1,0,0};
    bool dfs(int i, int j ,vector<int> &vis ,vector<vector<char>>& board,string &word ,int n, int m, int index ){
        if(index == word.size())return true;        
        vis[i*m+ j ]= 1 ;
        for(int z=0;z<=3; z++){
            int newi = i+ dx[z]; int newj = j+ dy[z];
            if(newi >=0 and newj >=0 and newi<n and newj <m and board[newi][newj] == word[index] and vis[newi*m + newj] == 0 ){
                if(dfs(newi , newj , vis , board , word , n ,m , index+1 ))return true;
            }
        }       
        vis[i*m + j] = 0;
        return false;        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<int > vis ( n*m , 0 );
        int index = 0 ;
        for(int i=0;i < n ;i++){
            for(int j = 0 ;j<m; j++){
                if(word[0] == board[i][j]){
                    if(dfs(i, j , vis, board, word,n , m,index +1  ))return true;
                }
            }
        }
        cout << word[index] << endl;
        return false;
    }
};