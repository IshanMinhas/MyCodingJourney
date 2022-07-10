#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    stack<pair< BinaryTreeNode<int > * , int >> st;
    vector<int > pre, in, post;
    if(root == NULL )return ans;
    st.push({root , 1});
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        if(node.second == 1){
            pre.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first ->left)st.push({node.first->left, 1});
        
        }else if(node.second == 2){
            in.push_back(node.first->data);
            node.second++;
            st.push(node);
            if(node.first ->right)st.push({node.first->right, 1});

        }
        else{
            post.push_back(node.first->data);
        }
               
    }
    
    
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    
    return ans;
    
}