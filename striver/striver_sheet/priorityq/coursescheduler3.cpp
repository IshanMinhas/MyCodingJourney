class Solution {
public:
    #define pi pair<int,int > 
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int > pq;int dayc = 0; 
        sort(courses.begin(),courses.end(), [](const vector<int > &a, vector<int > &b){
            return a[1]<b[1];
        });
        int n = courses.size();
        for(auto i : courses){
            dayc += i[0];
            pq.push(i[0]);
            if(dayc > i[1]){
                dayc-=pq.top();
                pq.pop();
            }
        }
    
        
      
        return pq.size();
    }
};