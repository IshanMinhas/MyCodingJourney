class Solution {
public:
    int numOfMinutes(int n, int source, vector<int>& manager, vector<int>& i) {
        unordered_map<int,vector<int> >m;
        for(int i=0;i<n;i++){
            m[manager[i]].push_back(i);
        }
        queue<pair<int , int > >q;
        q.push({i[source], source});
        int maxi = 0;
        while(!q.empty()){
            int node = q.front().second;
            int timetakentoinformnode = q.front().first;
            q.pop();
            for(auto it : m[node]){
                int x = it; int time = i[x];
                q.push({time + timetakentoinformnode, x});
                maxi = max(maxi , time + timetakentoinformnode);
            }
        }
        
        return maxi;        
    }
};