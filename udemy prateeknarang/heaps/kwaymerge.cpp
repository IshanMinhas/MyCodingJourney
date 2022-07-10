#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> mergeArrays(vector <vector <int>> arrs){
    int k =arrs.size(); // no of rows
    // triplets-> element , arra idx , element idx
    priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> q;
    vector <int>output;
    for(int i =0 ; i<k ; i++){
        int element = arrs[i][0];
        q.push({element,i,0});
    }
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        int Element = top[0];
        int a_idx = top[1];
        int e_idx = top[2];
        output.push_back(Element);
        if(e_idx +1 < arrs[a_idx].size()){
            q.push({arrs[a_idx][e_idx+1],a_idx,e_idx+1});

        }
    }
    return output;

}
int main(){
    vector<vector<int>> arr= {{10,15,20,30 },
                             {2,5,8,14,24},
                            {0,11,60,90} };
    
    vector<int>result = mergeArrays(arr);
    for(auto x: result){
        cout<< x<<"";

    }
}