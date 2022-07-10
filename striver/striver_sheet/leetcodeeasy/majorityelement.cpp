class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int c(-1), cnt(0);               // c = candidate, cnt = counter
        
        for(auto n: nums)
        {
            if (cnt == 0)
                c = n;
            cnt += (n == c) ? 1 : -1;
        }
        
        return c;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map <int , int > mp; 
        int ans = 0;
        for( int i = 0 ;i<nums.size() ; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp.insert(make_pair( nums[i] , 1));
                }
            else{
                mp[nums[i]]++;
            }
            ans = max(ans, mp[nums[i]]);
            
        }
        
        for(auto it : mp){
            if(it.second == ans)return it.first;
        }
        return 0;    }
};