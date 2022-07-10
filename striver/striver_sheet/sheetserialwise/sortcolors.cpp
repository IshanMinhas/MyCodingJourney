class Solution {
public:
   /* void swap(vector<int > &nums , int i , int j ){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

    
    }*/
    
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low =0; int mid = 0 ; int high  = n- 1;
        while(mid <=high){
            switch(nums[mid]){
                    // if ele is 0
                case 0:
                    swap(nums[low] , nums[mid]);
                    low++; mid++;
                    break;
                    
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid] , nums[high]);
                    high--;
                    break;
            }
        }
        
        
    }
};