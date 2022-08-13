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
    // dfs + memo
public:
    
  int answer ;
    pair<int ,int > helper(TreeNode * root){ // return with root and without root
        if(root == nullptr)return {0, 0 };
       pair<int , int >ans;
        pair<int, int > left = helper(root->left);
        pair<int , int > right =helper(root->right);
        int best_left = max(left.first , left.second);
        int best_right = max(right.first, right.second);
        ans.first = root->val + left.second + right.second;
        ans.second = best_left + best_right;
        answer = max({answer , ans.first , ans.second});
        return ans;
        
    }

    
    int rob(TreeNode* root) {
        answer = 0 ;
        
        helper(root);
        return answer;
    }
};