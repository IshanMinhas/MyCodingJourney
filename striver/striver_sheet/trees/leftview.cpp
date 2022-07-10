/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void recursion(TreeNode<int> * root , int level , vector<int > &ans){
    if(root == NULL )return ;
    if(ans.size() == level)ans.push_back(root->data );
    recursion(root->left , level + 1 , ans);
    recursion(root ->right , level +1 , ans);
    
    
}
vector<int> getLeftView(TreeNode<int> *root)
{
   // Your code here
   vector<int> ans;
   recursion(root , 0 , ans);
   return  ans; 
}
