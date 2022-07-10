#include<iostream>
#include<bits/stdc++.h>
using namespace std;



struct TreeNode{
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }



};
vector<int> Morrisinorder(TreeNode * root){
    vector<int> inorder;
    TreeNode * cur = root;
    while(cur!= NULL ){
        if(root ->left == NULL ){
            inorder.push_back(cur ->data);
            cur = cur->right;

        }else{
            TreeNode * prev = cur->left;
            while(prev->right != NULL and prev->right != cur){
                prev = prev->right;

            }
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur ->data);
                cur = cur->right;
            }
        }
    }
    return inorder; 







}