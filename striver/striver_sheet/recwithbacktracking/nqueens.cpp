class Solution {
    
public: 
    void f(int col , int n , vector<vector<string>>&ans, vector<string> &board ,vector<int> &Lrow ,vector<int> &Udiagonal , vector<int> &Ldiagonal   ){
            if(col == n){
                ans.push_back(board);
                return ;
            }
            
            for(int row = 0 ;row<=n-1 ; row++){
                if(Lrow[row] == 0 && Udiagonal[n-1 + col - row] == 0 && Ldiagonal[col + row] == 0 ){
                    board[row][col] = 'Q';
                    Lrow[row] = 1;
                    Udiagonal[n-1 + col - row] = 1;
                    Ldiagonal[row  +col ] = 1;
                    f(col + 1 , n , ans , board,  Lrow , Udiagonal , Ldiagonal);
                    board[row][col ] = '.';
                    Lrow[row] = 0;
                    Udiagonal[n-1  + col -row] = 0;
                    Ldiagonal[col + row] = 0;
                
                }
                
                
                
                
                
            }
        
        
        
        
        
    }
    
    
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n , '.');
        vector<int> Lrow(n , 0);
        vector<int> Udiagonal(2*n-1 , 0);
        vector<int> Ldiagonal(2*n-1 , 0);
        for(int i = 0; i<=n-1; i++){
            board[i] = s;
        }
        f( 0 , n , ans , board , Lrow, Udiagonal, Ldiagonal);
        return ans;
        
    }
};