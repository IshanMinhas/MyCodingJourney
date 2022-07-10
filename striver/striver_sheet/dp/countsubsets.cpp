#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int index , int target, vector<int> &vec,  vector<vector< int> >& dp){
    if(target ==0 )return 1;
    if(index == 0 )return (vec[0] == target); 
    if(dp[index][target]!= -1)return dp[index][target];
    int nottake = f(index -1 , target , vec, dp);
    int take = 0 ;
    if(target >= vec[index]){
        take  =f(index -1 , target- vec[index], vec, dp);
    }
    return dp[index][target] = take+nottake;
}

int f1( vector<int> vec , int target){
    int n = vec.size();

    vector<int > prev(target+1, 0 ) , cur(target+1 , 0 );

        prev[0] = 1 ; cur[0] = 1;
        if(vec[0]<= target)  prev[vec[0]] = 1;

    for(int i = 1; i< n ;i++){
        for(int j = 1; j<= target; j++){
                int nottake = prev[j ];
                int take = 0 ;
                if(j >= vec[i]){
                 take  =prev[j- vec[i]];
                    }
                 cur[j] = take+nottake;

        }
        prev = cur;
    }
    return prev[target];
}