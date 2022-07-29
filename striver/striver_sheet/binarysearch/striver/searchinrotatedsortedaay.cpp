class Solution {
public:
    
    

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0; int high = arr.size() - 1;
         while(high>=low){
             int mid = (low+high)/2;
             if(arr[mid] == target)return mid;
            if(arr[mid] >= arr[low]){
               
                if(target >= arr[low] && arr[mid] >= target)high = mid-1;
                else low = mid+1;
                
            }
            
            else {
            
                if(arr[mid] <= target and target <= arr[high])low= mid+1;
                else high = mid-1;  
                
                }
            }
        return -1;       
        
    }
};