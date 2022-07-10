#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int cuttingLog(int prices[] , int n){
    // base c
    if(n <= 0){ return 0;}
    // rec c
    int max_profit = INT_MIN;
    for( int i = 0 ; i<n ; i++){
        int cutlen = i+1;
        int profit = prices[i] + cuttingLog( prices , n- cutlen);
        max_profit = max(max_profit , profit);
    }
    return max_profit;
}



int max_profit_dp(int *prices , int n) {   
    int dp[n+1];
    dp[0] = 0;
    for(int len = 1 ; len<= n ; len++){
        int ans = INT_MIN;
        for( int i = 0 ; i< len; i++){
            int cut = i+1;
            int current_ans  = prices[i] + dp[len - cut];
            ans = max(ans , current_ans);
        }

        dp[len] = ans;
    }
    return dp[n];

}
int main(){
    int prices[] = { 3, 5, 8,9,10,17,17, 20};
    int n = sizeof(prices) / sizeof(int);

    cout << max_profit_dp(prices, n);

}