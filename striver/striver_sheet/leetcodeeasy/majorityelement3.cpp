//n/ k map
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector <int> f(vector<int > nums, int k){
    int n = nums.size();
    int me = n/k;
    unordered_map<int ,int > mp ; 
    for(int i =0; i< n; i++){
        if(mp.find(nums[i]) == mp.end()){
            mp.insert(make_pair(nums[i] , 1));
        }else{
            mp[nums[i]]++;
        }
    }
    vector <int > ans;
    for(auto x : mp){
        if(x.second >= me){
            ans.push_back(x.first);
        }
    }
return ans;
}