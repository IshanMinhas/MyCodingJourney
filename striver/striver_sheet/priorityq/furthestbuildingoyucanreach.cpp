class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        
        priority_queue<int > maxh;
        int i;
        int n = nums.size() ; 
        for(i = 1 ;i <= n-1 ;i++){
            int diff = nums[i] - nums[i-1]; 
            if(diff <= 0 )continue ; 
            bricks =bricks - diff;
            maxh.push(diff);
            if(bricks <0 ){
                bricks =bricks + maxh.top();
                if(ladders)ladders--;
                else break;
                maxh.pop();
            }   
           
        }
        
        return i-1;
        
        
    }
};