class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix[0].size(); int m= matrix.size();
      /* int low=0; int high = (n*m )-1;
        while(low<= high){
            int mid = (low+ high)>> 1;
            if(matrix[mid/n][mid%n]== target)return true;
            else if(matrix[mid/n][mid%n] < target)low = mid+1;
            else high=mid-1;    
        }
        return false;*/
        
        int i=0; int j = n-1 ;
        while(i<m and j>=0){
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j] > target)j--;
            else i++;
        }
        return false;
        
    }
};