#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int frog_min_cost( vector< int> stonesheight){
    vector <int> dp;
    int n =stonesheight.size();
    // base c
    dp[0] = 0;
    dp[1] = abs(stonesheight[1] - stonesheight[0]);

    // rec ca
    for(int i = 2 ; i<n ; i++){
        int op1 = abs(stonesheight[i] - stonesheight[i-1]) + dp[i-1];
        int op2 = abs(stonesheight[i] - stonesheight[i-2]) + dp[i-2];

        dp[i] = min(op1 , op2);


    }
return dp[n-1];




}

int main(){
    int n;
    cin >> n;
    vector< int> stonesheight;
    for(auto i = 0 ; i<n ; i++){
        cin >> stonesheight[i];
    }
    cout << frog_min_cost(stonesheight ) << endl;

}