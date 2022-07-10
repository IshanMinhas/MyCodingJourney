#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double findmed(vector<int > nums1 , vector<int >nums2){
    if(nums1.size() > nums2.size())return findmed(nums2, nums1);
    int n = nums1.size(); int m = nums2.size();
    int low =0; int high = n;
    while(high >= low){
        int cut1 = (low + high) >>1;
        int cut2 = (n+m+1)/2 - cut1;
        int left1 = cut1 == 0? INT_MIN : cut1 -1;
        int left2 = cut2 == 0? INT_MIN : cut2 -1;
        int right1 = cut1 ==n? INT_MAX : cut1;
        int right2 = cut2 ==n? INT_MAX : cut2;
        if(right2 >= left1 and right1 >= left2){
            if((n + m)% 2== 0) return (max(left1 , left2) + min(right1 , right2))/2;
            else return max(left1, left2);

        }
        else if(left1 > right2)high = cut1 -1;
        else low = cut1 +1;
    }
        return 0.0;







    }











