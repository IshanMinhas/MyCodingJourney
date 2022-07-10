#include<map>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int sz = start.size();
    vector<int> answer;
    map<pair<int,int>, int> val;
    for(int i = 0; i < sz; i++) {
        val.insert({{end[i], start[i]}, i+1});
    }
    int x = -1;
    for(auto &p : val) {
        if(x < p.first.second) {
            answer.push_back(p.second);
            x = p.first.first;
        }
        else if (x == p.first.first && p.second < answer.back()) {
            answer.back() = p.second;
        }
    }
    return answer;
}