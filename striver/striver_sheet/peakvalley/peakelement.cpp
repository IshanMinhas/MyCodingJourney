int findPeak(vector<int> &nums) {
    // Write your code here
      int low = 0 ; int high = nums.size()- 1;
        
        while(low < high){
            int mid = (low + high) >> 1;
            if(nums[mid + 1] <= nums[mid]){
                high = mid;
            }
            else{ 
                low = mid +1 ;
            }
            
        }
        return nums[low] ;
}
