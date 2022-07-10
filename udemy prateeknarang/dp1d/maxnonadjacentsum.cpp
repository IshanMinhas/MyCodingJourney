#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxnonAdjsum(vector <int> arr){

    int n = arr.size();
    vector< int> dp(n+1, 0);

    //  bottom up app

    if(n ==1){
        
        return dp[0];
    }
 
    dp[0] = arr[0];
    dp[1] = max(0 ,max(arr[0], arr[1]));
    for(int i = 2; i< n; i++){
        int inc = arr[i] + dp[i-2];
        int exc = dp[i-1];
        dp[i] = max(inc , exc);
        }
        return dp[n-1];



}


int main(){
    vector< int> arr ={ 6, 10 , 12 , 7, 9,14};
    cout << maxnonAdjsum(arr) << endl;



}