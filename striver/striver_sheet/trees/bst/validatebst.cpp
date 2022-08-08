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
    bool isValidBST(TreeNode* root) {
        return f(root , -1e14 , 1e14);
    }
    bool f(TreeNode * root ,long minv ,long maxv){
        if(root ==NULL)return true;
        if(minv >= root->val or maxv <= root->val )return false; //if root val is outside the range
        return f(root->left , minv , root->val ) && f(root->right , root->val , maxv);
    }
};