class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(); int m = b.size();
        if(n< m )return findMedianSortedArrays(b ,a);
        int low = 0 ; int high = a.size();
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n+m+1)/2 - cut1 ; 
            int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int right1 = cut1 ==  n ? INT_MAX : a[cut1] ;
            int right2 = cut2 ==  m ? INT_MAX : b[cut2] ;
            if(left1<= right2  && right1 >= left2){
                if((n+m)%2 == 0 )return (max(left1 , left2) + min(right1 , right2))/2.0;
                return max(left1 , left2);
            }
            else if(left1 > right2){
                high = cut1 - 1;
            }else{
                low = cut1 + 1;
            }
            
            
        }
        return 0.0;
    }
};





    }











