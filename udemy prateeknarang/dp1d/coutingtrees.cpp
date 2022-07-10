#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// exponential time comp
int catalan_number(int n ){
    if(n==0 or n==1){
        return 1;
    }
    int total = 0;
    for( int i= 1; i<= n ; i++){
        int left = catalan_number(i-1);
        int right = catalan_number(n-i);
        total += left*right;


    }
    return total;

}
// n^2 time cmp
int catalan_number_topdown(int n, vector<int> dp){
    
    
    
    // rec
    if(n==0 or n==1){
        return 1;
    }

    if(dp[n]!=0){
        return dp[n];
    }

    int total = 0;
    for( int i= 1; i<= n ; i++){
        int left = catalan_number_topdown(i-1, dp);
        int right = catalan_number_topdown(n-i, dp);
        total += left*right;
    }
    return dp[n] = total;


}
// bottom up
int catalan_number_bottomup(int n){
    vector<int> dp(n+1 , 0);
    dp[0] = dp[1]= 1;
    for(int i = 2 ; i<=n; i++){
        for(int j = 1; j<=i; j++){
            dp[i] += dp[j-1]*dp[i-j];

        }
    }

    return dp[n];


}

int main(){
    int n = 5;
    vector<int > dp(n+1 , 0);
    cout << catalan_number(n) << endl;
    cout << catalan_number_topdown(n , dp) << endl;
    cout << catalan_number_bottomup(n) <<endl;

}