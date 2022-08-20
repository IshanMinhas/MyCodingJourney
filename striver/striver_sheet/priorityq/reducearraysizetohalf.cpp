class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map <int ,int > mpp;
        priority_queue<int > pq; 
        for(auto it : arr)mpp[it]++; // store the freq of elements
        for(auto it : mpp)pq.push(it.second); // push in max pq 
    
        int res = 0 ; int count = 0 ; // res -> number of unique elem removed , count -> count of elements removed 
        while((arr.size() / 2)  > count){ // run the loop till we get atleast half the size of arr left
            res++ ; 
            count += pq.top() ; pq.pop();
        }
        return res;
    }
};