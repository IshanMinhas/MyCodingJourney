class Solution {
public: // twopointers
    int trap(vector<int>& height) {
     int l = 0 ; int r = height.size()- 1;
        int leftmax = 0 ; int rightmax = 0 ;
        int res = 0 ;
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] > leftmax)leftmax =height[l];
                else res+= leftmax - height[l];
                l++;
            }else{
                if(height[r] > rightmax )rightmax = height[r];
                else res+= rightmax - height[r];
                r--;
            }
        }
        return res;
    }
};

// we can use prefix sum array for left[i]
// we can use suffix sum arr for right[i]
//then calc min(left[i], right[i]) - a[i]; for every index