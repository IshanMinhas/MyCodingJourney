class Solution {
public:
    bool f(int i,int k , int target , int curr, vector<int > &vis,vector<int>& matchsticks ){
        
        if(k==0)return true;
        if(curr == target)return f(0, k-1 , target, 0 ,vis ,matchsticks);
        for(int j=i; j<matchsticks.size();j++){
            if(matchsticks[j]+ curr > target or vis[j])continue;
            vis[j] = 1;
            if(f(j+1 , k, target, curr+ matchsticks[j], vis, matchsticks))return true;
            vis[j]=0;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        vector<int > vis(n ,0);
        int target = 0;
        target = accumulate(matchsticks.begin(),matchsticks.end(), target);
       
        if(target%4 !=0 || target<4)return false;
        return f(0 , 3 , target/4 , 0 ,vis, matchsticks);
    }
};