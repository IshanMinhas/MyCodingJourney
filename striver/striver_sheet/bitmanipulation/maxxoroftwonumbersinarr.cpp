#include<bits/stdc++.h>
int maximumXor(vector<int> nums)
{
    // Write your code here.   

      int ans = 0 ; int prefix = 0 ;
      for(int i = 31; i>= 0 ;i--){
          prefix = prefix | (1<< i);
          unordered_set< int> s; 
          
          for(auto x : nums){
              s.insert(x & prefix) ; 
          }
          int c = ans| (1 << i);
          for(auto e : s){
            int b = e^c ; 
              if(s.find(b)!= s.end()){
                ans = c; 
                break ;
              }
          }
      }
        
        return ans;

}