int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
	//    Write your code here
            if(root == NULL)return -1; if(root->data == p or root->data == q )return root->data;
            int  left =  lowestCommonAncestor(root->left , p , q)  ;
            int right = lowestCommonAncestor(root ->right , p , q);
            if(left == -1)return right;
            else if(right == - 1)return left;
            else{return root->data;}
}