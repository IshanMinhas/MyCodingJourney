#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool divideAmongK(int a[] , int k ,int n , int min_coins){
    int partitions =0;
    int current_friend = 0;
    for(int i=0  ;i<n ;i++){
        if(current_friend + a[i] >= min_coins){
            partitions++;
            current_friend = 0;
        }
        else{
            current_friend +=a[i];
        }
    }
    return partitions >=k;



}
int k_partition(int *arr , int k, int n){
    int s=1;
    int e = 0;
    int ans;
    for(int i =0 ; i<n ; i++){
        e=e+arr[i];
    }
    while(s<=e){
        int mid = (s+e)/2;
        bool isPossible = divideAmongK(arr , k , n ,mid);
        if(isPossible){
            s = mid+1;
            ans =mid;
        }
        else{   
            e= mid -1 ;
        }
    }
return ans;
}

int main(){

    int a[] = { 1,2,3,4};
    int k =3;
    int n = sizeof(a)/sizeof(int);
    cout<< k_partition(a,k,n) << endl;



}