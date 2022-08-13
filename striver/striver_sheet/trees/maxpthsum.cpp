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
    int helper(TreeNode * root , int &ans){ // this fnc calc single path lh or rh maxi
        
        
        // ans stores the /\ path we can do this cuz we are taking maxi of 0 with both of the single path \ or / to avoi -ve paths
        if(root == NULL)return 0;
        int lh = max(0 , helper(root->left, ans));
        int rh = max(0 , helper(root->right, ans));
        ans = max(ans , root->val + lh + rh);
       
        return root->val + max(lh , rh);
    }
    int maxPathSum(TreeNode* root) {
      int ans = INT_MIN ;
        helper(root , ans );
        return ans;
    }
};