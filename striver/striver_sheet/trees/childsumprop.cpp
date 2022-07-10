void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL )return;
    int total = 0;
    if(root->left)total+=root->left->data;
    if(root->right)total+=root->right->data;
    if(total>= root->data)root->data = total;
    else{
        if(root->left)root->left->data = root->data;
        else if(root->right)root->right->data = root->data;
    }  
    
   
   
       changeTree(root->left);
       changeTree(root->right);
    int backtrack= 0;
    if(root->left)backtrack+=root->left->data;
    if(root->right)backtrack+=root->right->data;
    if(root->left or root->right)root->data = backtrack;
    
    
  
    
    

}  