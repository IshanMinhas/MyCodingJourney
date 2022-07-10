// best by bucket sort tc-o(n)
// priorityq - nlogk

#include<bits/stdc++.h>
#define pii pair<int,int>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
   // Write your code here.
   //using map and max heap
 
   unordered_map<int, int> mp;
   for(auto i: arr)
       mp[i]++;
   
   priority_queue<pii> pq;
   for(auto it: mp)
   {
       pq.push({it.second, it.first});
       
   }
   vector<int> ans;
   while(k--)
   {
       ans.push_back(pq.top().second);
       pq.pop();
   }
   sort(ans.begin(), ans.end());
   return ans;
   
}