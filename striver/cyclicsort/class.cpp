// we only move i forward when i is at the correect index
// check swap move
#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main(){
    /*
    kunal code
    int i = 0;
    while(i < n){
        int correct = arr[i]- 1;
        if(arr[i]!=arr[correct]){
            swap(arr[i] , arr[correct])
        }else i++;
    }
    */





    
    int arr[5] = {3 ,2 ,4, 1, 5};
    int n = 5;
    for(int i = 0 ;i < n; i++){
        if(arr[i] -1 != i ) {while(arr[i] - 1 != i ){
            swap(arr[i] , arr[arr[i]- 1]);
        }}
        else{
         continue;  
        }
}
for(auto x : arr){
    cout << x <<endl;
}
return 0;
}