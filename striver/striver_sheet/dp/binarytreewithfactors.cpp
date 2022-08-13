class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    int numFactoredBinaryTrees(vector<int>& arr) {
       unordered_map<ll, ll > mp; // for memory
        ll ans = 0 ; // the total no of b trees formed 
        sort(arr.begin(), arr.end()); // sorting cuz we need to find b trees with smallest nos first for dp
        int n = arr.size();
        for(int i=0; i<n; i++){ // running loop for all elements
            ll curr_ans = 1 ; // for element itself i.e b tree with 1 element arr[i]
            for(int j = 0;j< i;j++){ // trying to find more b trees for smaller arr[i] than the curr
                if(arr[i]%arr[j])continue; // if not divisible then we skip that no
                ll num1 = arr[j]; // the two nos
                ll num2 = arr[i]/arr[j];
                curr_ans = (curr_ans + (mp[num1]*mp[num2])%MOD)%MOD; // curr ans will be 1 + multi of the b trees by the divisors
            }
            mp[arr[i]] = curr_ans; // store in mem
            ans = (ans+curr_ans)%MOD; // sum all up
        }
        return (int)ans;
    }
};