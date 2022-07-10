#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// comp o(3^n)
// optimised sol in dynamic prog
int countWays(int n ){
    // base c
    if(n< 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    //rec c
    return countWays(n-1) +countWays(n-2) + countWays(n-3);


}
int main(){
    int n;
    cin>> n;
    cout<< countWays(n);
}