class Solution {
public:
    int n , m  ; int absmin = 1e9;
   int f(int i , int j , vector<vector<int>>& dungeon , vector<vector<int >> &dp ){
       if(i >= n   or j >= m  )return 1e9;
       if(i == n-1 and j == m-1)return (dungeon[i][j] <= 0 ) ? -dungeon[i][j] +1 : 1  ;
       if(dp[i][j]!=1e9)return dp[i][j];
       int mini = 1e9;
       
       int op1 = f(i+1 , j, dungeon , dp);
       int op2 = f(i , j+1, dungeon , dp);
       mini = min(op1 , op2) - dungeon[i][j];
       dp[i][j] = ( mini <= 0 ) ? 1 : mini;
     
       
       return dp[i][j] ;
       
   }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(); m = dungeon[0].size();
        vector<vector<int >> dp( n , vector<int > (m , 1e9 ));
        return f(0, 0, dungeon , dp);
        
    }
};