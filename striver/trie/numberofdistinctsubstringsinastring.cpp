//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
struct Node{
    Node * links[26];
    bool containsKey(char ch){
        return links[ch - 'a']!= NULL ;
        
    } 
    void put(char ch , Node * node){
        links[ch - 'a'] = node;
    }
    Node * get(char ch){
        return links[ch - 'a'];
    }
};

int countDistinctSubstring(string s)
{
    //Your code here
      int cnt = 0 ;
    Node * root = new Node();
    for(int i=0;i< s.size(); i++){
        Node * node = root;
            for(int j = i ;j< s.size(); j++){
                if(!node->containsKey(s[j])){
                    cnt++;
                    node->put(s[j], new Node());
                }
                node = node->get(s[j]);            
            }   
    }
    
    
    
    return cnt +1 ;
    
}