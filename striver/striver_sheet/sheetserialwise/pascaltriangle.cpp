class Solution {
public:
  

        
    
    vector<vector<int>> generate(int numRows) {
         
        
       vector<vector<int>> matrix(numRows); 
        

        for(int i= 0 ; i< numRows ; i++){
             matrix[i].resize(i+1);
             matrix[i][0] = 1;
             matrix[i][i] = 1;
            for(int j = 1; j<i ; j++){
                matrix[i][j] = matrix[i-1][j-1 ] + matrix[i-1 ][j];      
            }
        }
        
        return matrix;
        
        
        
    }
}