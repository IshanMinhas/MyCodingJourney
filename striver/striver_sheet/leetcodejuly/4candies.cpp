class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
       vector<int > left ( n ,1);
        for(int i=  0;i < n-1 ;i++){
            if(a[i]< a[i+1 ])left[i+1]  = left[i]+1;
        }
        for( int i = n-2 ; i>= 0 ; i--){
            if(a[i ]> a[i+1])left[i] = max(left[i] , left[i+1] + 1);
        }
        
        
        int cnt = 0 ;
        for(int i = 0 ; i< n ; i++){
            cnt += left[i];
        }
        return cnt;
        
        
        
        
        
        
        
    }
};