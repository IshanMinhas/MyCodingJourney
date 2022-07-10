// using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> res;
        
        for(int i = 0; i < arr.size(); i++)
        {
            // insert current element
			// insert current element only when the back of the deque is greater than cur
            int cur = arr[i];
            while(dq.empty() == false and arr[dq.back()] < cur)
                dq.pop_back();
            dq.push_back(i);
            
            // remove out of bound elements
            while(dq.empty() == false and dq.front() < i-k+1)
                dq.pop_front();
            
			// max element of the window will be the front of the deque
            if(i >= k-1)
                res.push_back(arr[dq.front()]);
        }
        return res;
    }
};



// pq
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
     priority_queue<pair<int,int>> pq; // element -> index
    // vec to store the results
    vector<int> res;
    // left and right bound of our window
    int right = 0, left = 0;

    // outer loop
    while(right < arr.size())
    {
        // add every element into the PQ
        pq.push({arr[right] , right});
        // window is not full... expand it
        if(right - left + 1 < k)
            right++;
        // window is full
        else if(right - left + 1 == k)
        {
            // remove the element not in the window from the PQ
            while(pq.top().second < left)
                pq.pop();
            // push the max elemnet from the window into the PQ
            res.push_back(pq.top().first);
            // slide the window
            left++; right++;
        }
    }
    return res;
    }
};