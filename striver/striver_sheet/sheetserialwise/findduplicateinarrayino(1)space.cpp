class Solution {
public: // o(n) , o(1)
    int findDuplicate(vector<int>& nums) {
        //cycle in a ll
        int slow = nums[0];
        int fast = nums[0];
        do{ 
        
            slow = nums[slow];
            fast = nums[nums[fast]];
        
        
        }while(slow != fast);
        
        fast = nums[0];
        //we use while loop here bcz if doubled element is the first ele of the arr then do while will not work eg - 3 1 3 4 2.  
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
        
    }
};

/* 1 CAN solve it with sorting T -o(nlogn) , s- o(!)
    2 Can solve it with map O(n) , o(n)
    3 CAN solve it by binary s - o(nlogn) , o(1)
