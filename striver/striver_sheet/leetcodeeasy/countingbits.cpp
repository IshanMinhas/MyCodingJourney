// nlogn
int f(int n ){
        vector<int > binaryno(32, 0 ); int count = 0 ;
        int i = 0 ;
        while(n > 0) {
            count += n%2;
            n= n/2;
            
        }
      return count;
        
    }
    
vector<int> count(int n)
{
	// Write your code here.
         vector<int> ans(n +1 , 0 );
        for(int i = 1 ;i < n+1; i++){
            ans[i] = f(i);
        }
        return ans;
}


//o(n)


vector<int> count(int n)
{
	// Write your code here.
            vector<int> ans(n +1 , 0 );
        for(int i = 1 ;i < n+1; i++){
            ans[i] = ans[i/2]  + i%2;
        }
        return ans;
}