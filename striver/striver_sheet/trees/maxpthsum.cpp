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
    
    int f(TreeNode * root , int &ans){
        if(root ==NULL)return 0;
        int lh = max(0 , f(root ->left, ans));
        int rh = max(0 ,f(root->right , ans));
        ans = max(ans , root->val + lh + rh);
        return root->val + max(lh,rh);
        
    }
    
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        f(root , ans);
        return ans;
    }
};