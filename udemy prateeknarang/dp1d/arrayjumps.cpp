#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top dowm
int array_jumps(vector<int> arr , int n , vector<int> dp , int i=0){
    //basec 
    if( i == n-1){
        return 0;
    }
    if(i>=n){
        return INT_MAX;
    }
    if(dp[i]!=0){
        return dp[i];
    }
    // rec c
    int steps = INT_MAX;
    int max_jump = arr[i];
    for(int jump =1;jump<=max_jump ;jump++ ){
        int next_index = i+jump;
        int sub_steps = array_jumps(arr , n , dp ,i + jump);
        if(sub_steps!=INT_MAX){
            steps = min(sub_steps + 1 , steps);
        }
    }
    return dp[i] =steps;
}

int main(){
    vector<int> arr ={ 3,4,2,1,2,3,7,1,1,3};
    int n = arr.size();
    vector<int> dp(n,0);
    cout << array_jumps(arr , n , dp , 0);
}