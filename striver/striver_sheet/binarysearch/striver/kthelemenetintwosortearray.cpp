#include<iostream>
using namespace std;

int kthelement(int array1[],int array2[],int m,int n,int k) {
    int p1=0,p2=0,counter=0,answer=0;
    
    while(p1<m && p2<n) {
        if(counter == k) break;
        else if(array1[p1]<array2[p2]) {
            answer = array1[p1];
            ++p1;
        }
        else {
            answer = array2[p2];
            ++p2;
        }
        ++counter;
    }
    if(counter != k) {
        if(p1 != m-1) 
            answer = array1[k-counter];
        else 
            answer = array2[k-counter];
    }
    return answer;
}

int main() {
    int array1[] = {2,3,6,7,9};
    int array2[] = {1,4,8,10};
    int m = sizeof(array1)/sizeof(array1[0]);
    int n = sizeof(array2)/sizeof(array2[0]);
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "
    <<kthelement(array1,array2,m,n,k);
    return 0;
}

//binary search
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(); int m = b.size();
        if(n< m )return findMedianSortedArrays(b ,a);
        int low = max(0 , k- m ) ; int high = min(k,n);
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = k - cut1 ; 
            int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int right1 = cut1 ==  n ? INT_MAX : a[cut1] ;
            int right2 = cut2 ==  m ? INT_MAX : b[cut2] ;
            if(left1<= right2  && right1 >= left2){
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