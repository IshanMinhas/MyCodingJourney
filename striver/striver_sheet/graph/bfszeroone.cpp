#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> bfszeroone(int source, int n, vector<int > adj[][]){
        deque<pair<int , int >> dq;
        vector<int > distv;
        distv.push_back(0);
        for(int i=1;i<n;i++){
            distv[i]=1e9;
        }
        dq.push_front({source , 0});
        while(!dq.empty()){
            int ver = dq.front().first;
            int dist = dq.front().second;
            dq.pop_front();
            for(auto it :adj[ver]){
                auto node = it.first;
                auto di = it.second;
                if(dist + di < distv[node]){
                    distv[node] = dist + di;
                    if(di==1){
                        dq.push_back({node, di+dist});
                    }else{
                        dq.push_front({node , di+dist});
                    }
                }
            }
        }
        return distv;







}