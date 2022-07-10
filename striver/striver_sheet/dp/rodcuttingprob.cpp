int f(int i , int w , vector<int> &profit ,vector<vector<int > >&dp ){
    if(i== 0 )return w*profit[0];
    
    if(dp[i][w]!=-1)return dp[i][w];
    int notTake = f(i-1 , w, profit, dp);
    int take = -1e9;
    if((i+1)<= w){
        take = profit[i] + f(i , w - i-1,  profit , dp);
        
    }
    return dp[i][w] = max(take , notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    int m = price.size();
    vector<vector<int> > dp(n , vector<int> (n +1 , -1));
    return f(n-1,  n , price, dp);
    
}


#include <bits/stdc++.h>

using namespace std;

int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp){

    if(ind == 0){
        return N*price[0];
    }
    
    if(dp[ind][N]!=-1)
        return dp[ind][N];
        
    int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
    
    int taken = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= N)
        taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
        
    return dp[ind][N] = max(notTaken,taken);
}


int cutRod(vector<int>& price,int N) {

    vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);   
        }
    }
    
    return cur[N];
}



int main() {

  vector<int> price = {2,5,7,8,10};
  
  int n = price.size();
                                 
  cout<<"The Maximum price generated is "<<cutRod(price,n);
}