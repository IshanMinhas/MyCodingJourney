/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,pair<int,vector<int>>> mp;
        queue<int> q;
        int ans=0;
        //Created a map like this
        // 1 -> pair{5 , [2,3] }
        for(Employee* e:employees){
            mp[e->id] = {e->importance,e->subordinates};
        }
        //pushed the first element to q
        q.push(id);
        
        //implement bfs
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            //add the importance of current popped element
            ans+=mp[curr].first;
            //add all of it's child to the queue
            for(int i:mp[curr].second){
                q.push(i);
            } 
        }
        return ans;
    }
};