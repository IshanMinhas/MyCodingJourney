class Solution {
public:
    int f(int i , int j , vector<int > &price, vector<vector< int>> &dp){
        if(i > j )return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = 1e9;
        for(int ind = i ; ind<=j ;ind++){
            int cost = price[j+1 ] - price[i-1] + f(i ,  ind-1, price, dp) + f(ind+1 ,j, price, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& price) {
        
        int c = price.size();
        price.push_back(n);
        price.insert(price.begin(), 0 );
        sort(price.begin(), price.end());
        vector<vector<int > > dp(c +1, vector<int > (c+1 , - 1));
        return f(1, c , price, dp);
    }
};