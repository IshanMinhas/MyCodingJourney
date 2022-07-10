class Solution {
    
public: 
   bool check(int row, int col , vector<string> &ds){
        
        int dupr = row;
        int dupc = col;
        while(col>= 0 ){
            if(ds[row][col--]== 'Q')return false;   
        }
        row = dupr;
        col = dupc;
        while(row>=0 and col>=0){
            if(ds[row--][col--] == 'Q')return false;      
        }
        row = dupr;
        col = dupc;
        while(row<ds.size() and col>=0 ){
            if(ds[row++][col--] == 'Q')return false;
        }
        
        return true;
    }
    
    
    
    
    
    
    
    
    void helper(int col , int n, vector<vector<string > >&ans , vector<string > &ds){
        if(col == n){
            ans.push_back(ds);
            return;
        }
        
        
        for(int row = 0 ;row< n ;row++ ){
            if(check(row, col , ds)){
                ds[row][col] = 'Q';
                helper(col + 1, n , ans , ds);
                ds[row][col] = '.';
            }
        }           
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string  > > ans; 
        vector<string> ds(n);
        string s(n , '.');
        for(int i=0;i<n;i++)ds[i] = s;
        
        helper( 0 , n , ans, ds);
        return ans;
        
        
        
    }
    
};