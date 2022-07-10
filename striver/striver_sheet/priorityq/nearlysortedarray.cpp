#include<bits/stdc++.h>
vector < int > nearlySorted(vector < int >input, int n, int k) {
    // Write your code here.
    vector<int > res; priority_queue<int, vector<int> , greater<int >> minh;
    for(int i=0 ;i< n ;i++){
        minh.push(input[i]);
        if(minh.size()>k){
            res.push_back(minh.top());
            minh.pop();
        }
    }

    while(minh.size()){
        res.push_back(minh.top());
            minh.pop();
    }
        return res;
}