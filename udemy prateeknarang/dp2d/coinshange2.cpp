#include<iostream>
#include<bits/stdc++.h>>
using namespace std;

long long coinchange2(int n , vector< int > &denoms ,vector<vector<int>>dp , int v){
    if(n < 0){
        return 0 ;
    }
    if(v == 0){
        return 0;    }
    if(n == 0){
        return 1;
    }
    if(dp[n][v] != 0){
        return dp[n][v];

    }
    if(denoms[v-1] <= n){
        return dp[n][v] = coinchange2(n - denoms[v-1] , denoms , dp , v) + coinchange2(n , denoms, dp , v-1);

    }
    else{
        return dp[v][n] = coinchange2(n , denoms, dp , v-1);
    }

    




}
int fnc(int n ,  vector<int> denoms){
    // n = target value , v = arr.length;
    vector<vector<int>>dp ;

}

int main(){
    int n;
    cin>> n;
    vector<int> denoms = { 1,2,3};
    
    cout << fnc(n , denoms);



}