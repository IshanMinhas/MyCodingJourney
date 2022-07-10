#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int join_ropes(int ropes[] , int n){
    priority_queue< int ,vector<int> , greater<int> > pq(ropes , ropes + n);
    // ^min heap in built fnc
    int cost =0;
    while(pq.size() >1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int newrope = (a+b);

        cost += (a+b);
        pq.push(newrope);

    }
    return cost

    ;
}
int main(){
    int a[] = {4,3,2,6};
    int n =4;
    cout << join_ropes(a, n) << endl;



}