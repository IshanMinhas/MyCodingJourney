// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    
    void f(int i , int j ,vector<string> &ans ,vector<vector<int>> &vis , vector<vector<int>> &m, int n, string ends ){
        if( i == n-1 and j == n-1){
            ans.push_back(ends);
            return ;
        }
        
        // down
        if(!vis[i+1][j] and m[i+1][j] == 1 and i+1 < n  ){
            
            vis[i][j] = 1;
            f(i+1, j , ans , vis , m , n , ends + 'D');
            vis[i][j] = 0;
        }
        // left
         if(!vis[i][j-1] and m[i][j-1] == 1 and j-1>=0 ){
            
            vis[i][j] = 1;
            f(i, j-1 , ans , vis , m , n , ends + 'L');
            vis[i][j] = 0;
        }
        //right
         if(!vis[i][j+1] and m[i][j+1] == 1 and j+1<n ){
            
            vis[i][j] = 1;
            f(i, j+1 , ans , vis , m , n , ends + 'R');
            vis[i][j] = 0;
        }
        
        // up
         if(!vis[i-1][j] and m[i-1][j] == 1 and i-1>=0  ){
            
            vis[i][j] = 1;
            f(i-1, j , ans , vis , m , n , ends + 'U');
            vis[i][j] = 0;
        }
       
    }
    
   
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n ,vector<int> (n,0));
        if(m[0][0] == 1) f(0 , 0 , ans, vis , m , n ," ");
        return ans;
        
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends










//optimised
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  
    void f(int i , int j ,vector<string> &ans ,vector<vector<int>> &vis , vector<vector<int>> &a, 
    int n, string move, int di[], int dj[] ){
            if( i == n-1 && j == n-1){
                ans.push_back(move);
                return ;
            }
        
            string dir = "DLRU";
            for(int ind = 0 ; ind < 4 ; ind++){
                 int nexti = i + di[ind];
                int nextj = j + dj[ind];
                if(nexti>= 0 && nextj>=0 and nexti < n and nextj < n and !vis[nexti][nextj] and a[nexti][nextj] == 1){
                        vis[i][j] = 1;
                        f(nexti , nextj , ans, vis , a , n , move + dir[ind]  , di ,dj);
                        vis[i][j] = 0;
                 
                } 
            }
            
            
            
            
            
            
            
            
         }
     
    
   
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n ,vector<int> (n,0));
        int di[] = { +1 , 0 , 0 ,-1 };
        int dj[]  = {0 , -1 , +1 , 0};
        if(m[0][0] == 1) f(0 , 0 , ans, vis , m , n ,"", di , dj);
        return ans;
        
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends