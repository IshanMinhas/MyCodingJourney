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
            pq.push(i[0]); // pushing the element in the pq even if it is bigger 
            // if it is bigger then it will removed in the next
            if(dayc > i[1]){//we are keeping the smallaer element inside the pq, and removing the bigger i[0] ones by keeping the count same 
                dayc-=pq.top();
                dayc-=pq.top();
                pq.pop();
            }
        }
    
        
      
        return pq.size();
    }
};