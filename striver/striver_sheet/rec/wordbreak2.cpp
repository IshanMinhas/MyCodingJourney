#include<bits/stdc++.h>
void helper(set<string > s, string & target ,int index, vector<string > &ds, vector<string> &ans, string str){
    if(index == target.size()){
        for (const auto &piece : ds) str +=  piece + " "; 
        
        str.pop_back();
        ans.push_back(str);
        return ;
    }

    
    
    string temp ="";
    //if(dp[index]!=-1)return dp[index];
    for(int i= index; i<target.size() ; i++){
        temp.push_back(target[i]);
        if(s.find(temp) != s.end()){
            ds.push_back(temp);
            
            helper(s , target , i+1 , ds, ans, str);
            ds.pop_back();          
        }
    
    }
}

vector<string> wordBreak(string &target, vector<string> &arr)
{
    // Write your code here
  vector<string > ans; vector<string> ds;
     set<string >s; string str;
    for(auto x : arr)s.insert(x);
     helper(s , target ,0 , ds, ans ,str);
    return ans;
}