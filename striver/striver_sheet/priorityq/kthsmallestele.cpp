#include<bits/stdc++.h> 
int kthSmallest(vector<int> input, int k)
{
    // Write your code here.
    int n = input.size();priority_queue<int > maxh;
    for(int i=0 ;i< n ;i++){
        maxh.push(input[i]);
        if(maxh.size()>k){   
            maxh.pop();
        }
    }
    return maxh.top();
}