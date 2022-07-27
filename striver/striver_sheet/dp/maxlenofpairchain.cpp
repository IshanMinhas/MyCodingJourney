class Solution {
public:
    static bool comp(vector<int > &a, vector<int > &b){
        if(a[1] == b[1])return a[0]<b[0];
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(), comp);
        int n = pairs.size();
        int cnt = 1 ;
        int i= 0 ;
        int j = 1; 
        while(j < n and i<n){
            if(pairs[i][1] < pairs[j][0]){
               cnt++;
                i =j;
                j++;
            }
            else if (pairs[i][1] >= pairs[j][0]){
                j++;
            }
            cout << j << endl;
        }
        
        return cnt;
    }
};