#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Compare{
    public:
    bool operator()(int a , int b){
        return a>b;
    }
};
int main(){

    int arr[] ={ 10 , 90 , 15, 13, 8};
    int n = sizeof(arr)/sizeof(int);
    // priority_queue<int> heap; // by default it is max heap
    
    priority_queue<int , vector<int> , Compare  /*, greater<int>*/ > heap; // for min heap, greater is inbuilt comparator
    for( int x: arr){
        heap.push(x);
    }
    while(!heap.empty()){
        cout << heap.top() << endl;
        heap.pop();
    }





}