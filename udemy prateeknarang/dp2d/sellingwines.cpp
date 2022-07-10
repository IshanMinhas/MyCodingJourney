#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int wines(int dp[][10], int prices[] , int L, int R , int year){

    if(L> R){
        return 0 ;
    }

    if(dp[L][R] != 0){
        return dp[L][R];
    }

    int Lopt = prices[L] *year  + wines(dp , prices , L+1 , R , year+1);
    int Ropt = prices[R]*year  + wines(dp ,prices ,  L , R-1 , year +1);

    return dp[L][R] = max(Lopt , Ropt);






}

int wines_bottom_up(int prices[] , int n){
    vector< vector<int>> dp1(n , vector<int> (n ,0 ));


    for(int i=n-1 ; i>=0; i--){
        for(int j = 0; j<n ; j++){
            if(i== j){

                dp1[i][j] = prices[i]*n;
            }
            
            if(i<j){
                int y = n - (j-i);
                int leftopt = prices[i]*y + dp1[i+1][j];
                int rightopt = prices[j]*y + dp1[i][j-1];
                dp1[i][j] = max(leftopt , rightopt);




            }
        }
    }


    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<n ; j++){
            cout << dp1[i][j] << ", ";
        }
        cout << endl;

    }





    return dp1[0][n-1];



}




int main(){

    int a[] = {2,3,5,1,4};
    int n = 5;
    // int dp[10][10] = {0};
    // cout << wines(dp,a, 0 ,n-1, 1) << endl;
    
    cout << wines_bottom_up(a, n) << endl;





}