#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>> minheap;
    int d;
    cin >>d;
    maxheap.push(d);
    float median = d;
    cout<< median <<"";
    cin>> d;
    while(d!=-1){
        if(maxheap.size() > minheap.size()){
            if(d<median){
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(d);
            }
            else{
                minheap.push(d);
            }
             median = (maxheap.top()+minheap.top())/2.0;
        }
        else if(maxheap.size() == minheap.size()){
            if(d<median){
                maxheap.push(d);
                median = maxheap.top();
            }
            else{
                minheap.push(d);
                median = minheap.top();
            }}

            else{
                if(d<median){
                    maxheap.push(d);
                }
                else{
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(d);
                }
                median = (maxheap.top()+minheap.top())/2;
            }
            cout <<median <<"";
        cin>> d;
       
        }
        
    } 






