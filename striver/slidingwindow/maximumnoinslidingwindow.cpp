// Better to solve with dq
// first there is pq ans then dq











// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        // your code here
         vector<int>ans; priority_queue<pair<int,int>> pq; 
        int left= 0; int right=0;
        while(right <= n- 1){
            pq.push({nums[right], right });
            if(right - left + 1 <k  ){
                right++;
            }
            
            else if(right - left + 1 == k){
                
                while(pq.top().second <left)pq.pop();
                
                ans.push_back(pq.top().first);
                left++; right ++;
                
                
                
                
            }
            
        
            
            
            
        }
      return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends












//can be solved using DQ
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        int n=nums.size();
        deque <int> q; //only indexes are stored
        for(int i=0;i<n;i++)
        {   
            while(!q.empty() && i-q.front()>=k)
                q.pop_front(); //only window size of k is allowed
            while(!q.empty() && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);
            if(i>=k-1)ans.push_back(nums[q.front()]); //our max value in O(1)
        }
        return ans;
    }
};
