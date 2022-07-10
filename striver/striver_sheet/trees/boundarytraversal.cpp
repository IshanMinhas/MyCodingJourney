#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>  * root){
    if(root->right == NULL and root->left == NULL)return true;
        else return false;
}
void helper1(TreeNode<int> * root, vector<int > &ans){
    TreeNode<int> *cur = root->left;
    while(cur!= NULL){
        if(!isleaf(cur)) ans.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur= cur->right;   
    } 
}
void helper2(TreeNode<int> * root, vector<int > &ans){
    
    TreeNode<int> * cur =  root->right;
    vector<int> temp;
    while(cur!= NULL){
        if(!isleaf(cur)) temp.push_back(cur->data);
        if(cur->right)cur = cur->right;
        else cur = cur->left;   
    } 
   reverse(temp.begin() , temp.end());
    for(int i = 0 ; i<temp.size(); i++){
        ans.push_back(temp[i]);
    }
    
    
    
}
void helper3(TreeNode<int> * root, vector<int > &ans){
    if(isleaf(root)){
        ans.push_back(root->data);
        return; }
    if(root ->left) helper3(root->left , ans);
    if(root->right) helper3(root->right ,ans);
    
    
    
    
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int > ans;
    if(root == NULL )return ans;
    if(!isleaf(root)) ans.push_back(root->data);
    helper1(root,ans);
    helper3( root , ans);
    helper2(root , ans);
    return ans;
    }