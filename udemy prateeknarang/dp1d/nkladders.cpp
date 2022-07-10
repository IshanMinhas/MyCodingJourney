// bottom up
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// rec -> o(k^N)
int countWays(int n, int k){
    // base c
    if(n == 0){
        return 1;
    }
    //rec c
    if(n<0){
        return 0;
    }
    int ans=0;
    for(int jump = 1 ; jump<= k ; jump++){
        ans += countWays(n-jump , k);
    }

    return ans;
}

//o(n*k)
int countWaysTD(int n, int k, int *dp){
    // base c
    if(n == 0){
        return 1;
    }
    //rec c
    if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }

    int ans=0;
    for(int jump = 1 ; jump<= k ; jump++){
        ans += countWaysTD(n-jump , k, dp);
    }

    return dp[n] =ans;
}


//o(n*k)
int countWaysBU(int n , int k ){
    vector<int> dp(n+1 , 0);
    dp[0] = 1;
    for(int i = 1 ; i<=n ; i++){

        for(int jump = 1 ; jump<= k ; jump ++){
            if(i-jump >= 0){
                dp[i] = 2*dp[i-jump];
            }
        }
    }


    return dp[n];
}
// fastest way
int coutWaysOptim(int n , int k ){

    vector< int> dp(n+1 , 0);
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i<=k ; i++){
        dp[i] = 2*dp[i-1];

    }
    for(int i = k+1 ; i<= n ; i++ ){
        dp[ i ] = 2*dp[i-1] - dp[i-k-1];
    }


return dp[n];
}




int main(){
    int n , k;
    cin >> n >>k;

    int dp[1000] = {0};
    //cout << countWaysTD(n , k , dp) << endl;
    cout << coutWaysOptim(n , k) << endl;
    cout << countWaysBU(n , k)<< endl;
    






}

