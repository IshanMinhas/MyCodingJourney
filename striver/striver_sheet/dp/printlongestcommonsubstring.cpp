#include <bits/stdc++.h>

using namespace std;

int lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    int rowno = 0;
    int colno = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                if(ans <= val){
                    ans = val;
                    rowno = i ;
                    colno = j ;
                }
            
            }
            else
                dp[i][j] = 0;
        }
    }
    rowno-- ; colno--; 
    string ttt = "";
    while(colno){
        ttt += s2[colno--]; 
    }
    reverse(ttt.begin() , ttt.end()) ;
    cout << ttt ;
    return ans;

    
}

int main() {

  string s1= "abcjklp";
  string s2= "acjkp";
                                 
  cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2);
}