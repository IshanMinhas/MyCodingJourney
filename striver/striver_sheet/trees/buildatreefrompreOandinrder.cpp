    
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode *find(vector<int> &preorder, vector<int> &inorder, int is, int ie)
    {
        if (is > ie)
        {
            return NULL;
        }
        int x = preorder[preIndex++];
        TreeNode *root = new TreeNode(x);
        if (is == ie)
            return root;
        int inIndex = mp[x];
        root->left = find(preorder, inorder, is, inIndex - 1);
        root->right = find(preorder, inorder, inIndex + 1, ie);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return find(preorder, inorder, 0, n - 1);
    }
};