/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* cur, int val) {
        
        TreeNode * root = cur;
        if(root == NULL)return new TreeNode(val);
        while(true){
            if(root->val <= val ){
                if(root->right!=NULL)root = root->right;
                else{
                    root->right = new TreeNode(val);
                    break;
                }
            }else{
                if(root->left!=NULL)root = root->left;
                else{
                    root->left = new TreeNode(val);
                    break;
                }
            }
        }
        return cur;
    }
};