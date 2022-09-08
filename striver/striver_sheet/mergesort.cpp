#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr , int i , int j ){
    int mid = (i +j )>>1;
    int len1 = mid - i + 1;
    int len2 = j - (mid +1) + 1;
    int * arr1 = new int[len1];
    int * arr2 = new int[len2];
    
    
    
    
    
    int k = i;
    for(int z = 0; z< len1; z++)arr1[z] = arr[k++];
    k = mid +1 ;
    for(int z = 0; z< len2; z++)arr2[z] = arr[k++]; 
    // merge




    int index1= 0 , index2 = 0 ; k = i;
    while(index1 < len1 and index2 < len2){
        if(arr1[index1] < arr2[index2]){
            arr[k++] = arr1[index1++ ];
        }else{
            arr[k++] = arr2[index2++]; 
        }
    }
    while(index1 < len1){
        arr[k++] = arr1[index1++];
    }
    while(index2 < len2){
        arr[k++] = arr2[index2++];
    }

    delete arr1 ; delete arr2;



}


void mergeSort(int arr[] , int i , int j){
    if(j <= i)return;
    int mid = (i + j) >> 1;
    mergeSort(arr, i , mid);
    mergeSort(arr, mid + 1 , j);
    merge(arr , i , j);



}

int main(){
    int arr[5] = { 2,5,1,6,9};
    int n = 5;
    mergeSort(arr, 0 , n-1 );
    for(auto x : arr){
        cout << x <<endl;
    }
    return 0;
}