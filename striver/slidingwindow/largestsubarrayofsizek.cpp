// for positive nos
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int k , int n ){
    int i , j = 0; int sum = 0 ; int maxi = 0;
    while(j < n ){
        sum = sum + arr[j];
        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxi = max(maxi , j-i +1 );


            j++;
        }
        else{
            while(sum > k ){
                sum = sum - arr[i];
                i++;
            }
            if(sum == k)maxi = max(maxi , j-i +1 );
            j++;
        }
    }
    return maxi;
}



//for -ve nos
// peak valley 
// we store the key as sum as we are checking for sum == k in the map and index and value
// cuz we want the maxi of the windows
// we use map cuz of -ve nos sumgoes up and down so we need to store sum of prev indices 
// if sum was == k then we get our ans or if sum was already presestn then we get our ans
// and we push  0 as the key and its value as -1 as we are using 0 indexing
//{ Driver Code Starts

// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int k) 
    { 
        // Complete the function
        int i , j = 0 ; int maxi = 0 ; int sum = 0 ;
        unordered_map < int , int  > mpp;
        mpp[0] = -1;
        for(int i= 0 ;i < N ;i++){
            sum = sum+ arr[i];
            if(mpp.find(sum - k )!= mpp.end())maxi = max(maxi , i - mpp[sum - k ]);
            if(mpp.find(sum) == mpp.end())mpp[sum] =i; 
            
        }
        return maxi; 
        
        
    } 

};
