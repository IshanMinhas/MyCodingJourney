#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// AMORTIZED TIME COMP o(N)


struct TreeNode{
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }



};
vector<int> Morrispreorder(TreeNode * root){
    vector<int> preorder;
    TreeNode * cur = root;
    while(cur!= NULL ){
        if(root ->left == NULL ){
            preorder.push_back(cur ->data);
            cur = cur->right;

        }else{
            TreeNode * prev = cur->left;
            while(prev->right != NULL and prev->right != cur){
                prev = prev->right;

            }
            if(prev->right == NULL){
                prev->right = cur; preorder.push_back(cur ->data);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
               
                cur = cur->right;
            }
        }
    }
    return preorder; 
