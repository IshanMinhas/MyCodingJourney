#include<bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    
   //    Write your code here.
    vector<int>give;
   map<int,map<int,vector<int>>> nodes;
   queue<pair<TreeNode<int>*,pair<int,int>>>q;
   if(root == nullptr) return give;
   q.push({root,{0,0}});
   while(!q.empty()){
       auto p= q.front();
       q.pop();
       TreeNode<int>* temp = p.first;
       int x = p.second.first;
       int y= p.second.second;
       nodes[x][y].push_back(temp->val) ;
       if(temp->left){
           q.push({temp->left,{x-1,y+1}});
       }
       if(temp->right){
           q.push({temp->right,{x+1,y+1}});
       }
   }
   
   vector<vector<int>> ans;
   for(auto it : nodes){
       vector<int> col;
       for(auto p : it.second){
           col.insert(col.end(),p.second.begin(),p.second.end());
       }
       ans.push_back(col);
   }
  
   for(auto it : ans){
       
           give.push_back(it[0]);
       
   }
   return give;
   




}