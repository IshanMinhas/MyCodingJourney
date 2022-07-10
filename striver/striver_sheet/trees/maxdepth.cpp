//TreeNode class definition
/*
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

*/

int findMaxDepth(TreeNode<int> *root) 
{
	//Write your code here. 
        if(root == NULL)return 0;
        int lh = findMaxDepth(root->left);
        int rh = findMaxDepth(root->right);
        return 1 + max(lh ,rh);
}