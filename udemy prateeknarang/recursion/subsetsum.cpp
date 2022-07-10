#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// this also has overlapping subp ,optimise by DP

int countSubsets(vector<int> arr , int n , int i ,int X){
    //base 
    if(i == n){
        if(X == 0){
            return 1;
        }
        return 0;
    }

    // rec
    int inc = countSubsets(arr , n , i+1 , X  - arr[i]);
    int exc = countSubsets(arr , n , i+1 , X);
return inc +exc;
}
int main(){

    vector<int> arr { 1 , 2 , 3 ,4,5};
    int X = 6;
    cout<< countSubsets(arr , arr.size() , 0, X);


}