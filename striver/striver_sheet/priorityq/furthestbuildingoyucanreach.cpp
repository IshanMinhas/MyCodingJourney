class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        //kind of dp style of thinking where we go back in our logic on the basis of the future values of bricks and ladders 
        priority_queue<int > maxh;
        int i;
        int n = nums.size() ; 
        for(i = 1 ;i <= n-1 ;i++){
            int diff = nums[i] - nums[i-1];  // only need +ve diff
            if(diff <= 0 )continue ; 
            bricks =bricks - diff; // no of bricks used
            maxh.push(diff);// pushing the diff as we want to use the max diff for the ladders
            if(bricks <0 ){ // if bricks are - ve we r gonna replace max consumption of bricks with the ladders
                bricks =bricks + maxh.top();
                if(ladders)ladders--;
                else break;
                maxh.pop();
            }   
           
        }
        
        return i-1;
        
        
    }
};