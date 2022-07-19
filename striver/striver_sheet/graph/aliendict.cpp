#include<bits/stdc++.h>
vector<int > f(vector<int> adj[], int n ){
    vector<int > indegree(n , 0);
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int >ans;
    while(!q.empty()){
        int node = q.front();
        q.pop(); ans.push_back(node);
        for(auto it :adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }           
    }
    
    return ans;
    
    
    
}

vector<char> getAlienLanguage(string* a, int n)
{
    // Write your code here.
    unordered_set<char> mpp;
    for(int i=0;i<n;i++){
        for(auto it:  a[i]){
            mpp.insert(it);
        }
    }
    
    int mppsize = mpp.size();
    vector<int> adj[mppsize];
    for(int i=0;i<n-1;i++){
        string cur = a[i];
        string next = a[i+1];
        int m= min(cur.size(), next.size());
        for(int j=0;j<m;j++){
            if(cur[j]!=next[j]){
                adj[cur[j] - 'a'].push_back(next[j]- 'a');
                break;
            }
        }      
    }
    vector<int > op = f(adj , mppsize);
    vector<char>ans;
    for(int i=0;i<op.size();i++){
        ans.push_back(op[i]+ 'a');
    }
    return ans;
    
    // edge case
    
    
    
    
    
    
    
    
    
}