#include<bits/stdc++.h>
int dp[300];
bool helper(set<string > s, string & target ,int index){
    if(index == target.size())return 1;
    
    string temp ="";
    if(dp[index]!=-1)return dp[index];
    for(int i= index; i<target.size() ; i++){
        temp.push_back(target[i]);
        if(s.find(temp) != s.end()){
            if(helper(s , target , i+1))return dp[index] = 1;
        }
    
    
    }
    return dp[index] = 0;
}





bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    memset(dp ,- 1, sizeof dp);
     set<string >s;
    for(auto x : arr)s.insert(x);
    return helper(s , target ,0);
    
}