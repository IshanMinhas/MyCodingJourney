// 1 lazy approach is sorting where time comp is k*n*logn







//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string txt, string pat) {
	    // code here
	    int n = txt.size();
	    map<char , int > mpp1;
	    map<char, int  >mpp2;
	    for(auto x : txt)mpp2[x]++;
	    
	    
	    int i =0, j = 0; int cnt= 0;
	    
	    
	    while(j < pat.size()){
	        if(j -i +1 < n) mpp1[pat[j]]++,j++ ;
	       
	        else if(j-i +1 == n){
	            mpp1[pat[j]]++;
	            if(mpp1 == mpp2)cnt++;
	            mpp1[pat[i]]--;
	            if(mpp1[pat[i]] == 0)mpp1.erase(pat[i]);
	            
	            i++ ; 
	            j++ ;
	        }
	    }
	    return cnt;
	
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends