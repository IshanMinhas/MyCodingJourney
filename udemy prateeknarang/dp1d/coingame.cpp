#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// bottom up
int coingame( int m , vector< int> denoms){

    vector< int> dp( m+1 , 0);
    dp[0] = 0;
    for( int i =1 ; i<= m ; i++){
        dp[i] = INT_MAX;
        for(int coin : denoms ){
            if(i - coin >=0 and dp[i-coin] != INT_MAX){
                dp[i] = min( dp[i] , dp[i- coin] + 1); 

            }
        }
    }

return dp[m]== INT_MAX? -1 : dp[m];





}

int main(){

    vector< int> denoms = {5,7,10};
    int m = 3;
    cout<< coingame(m , denoms);



}