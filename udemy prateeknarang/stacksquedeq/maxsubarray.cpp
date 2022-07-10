#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void maxSubarray(vector<int> arr, int k){
    deque<int> Q(k);
    for(int i =0 ; i<k ;i++){
        while(!Q.empty() and arr[i] > arr[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for(int i=k ; i<9 ; i++){
        cout << arr[Q.front()]<< endl;
        while(!Q.empty() and Q.front() <= i-k ){
            Q.pop_front();
        }
        while(!Q.empty() and arr[i] > arr[Q.back()] ){
            Q.pop_back();
        }
        Q.push_back(i);
    }







}   
int main(){
    vector<int> arr {1,2,3,1,4,5,2,3,6};
    int k;cin>>k;
    maxSubarray(arr , k);
}