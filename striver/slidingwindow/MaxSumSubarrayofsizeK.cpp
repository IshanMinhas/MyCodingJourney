//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i = 0; int j = K-1; 
        long maxi = 0 ;
        long sum = 0;
        for(int k = 0; k <= j; k++)sum+=Arr[k];
        maxi = max(sum , maxi);
        while(j < N-1){
            j++ ; 
            sum += Arr[j];
            sum -=Arr[i];i++;
        
            maxi = max(sum , maxi);            
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends