 //rec
 int total = 0;
    void helper(TreeNode * root , int targetSum ,long long int Sum ){
            if(root ==NULL)return;
            Sum+= root->val;
            if(Sum == targetSum)total++;
            
            helper( root->left , targetSum, Sum);
            helper(root->right , targetSum , Sum);
    
            
    
    
    
    }
    int pathSum(TreeNode* root, int targetSum){
            if(root == NULL)return 0;
              
            helper(root , targetSum ,0);
           
            pathSum(root->left , targetSum);
            pathSum(root->right , targetSum);
            return total;
        
    }
// gain approach


    int total = 0;
            
    void helper(TreeNode * root , int targetSum , map<int ,int> &m, long long int Sum ){
        if(root == NULL)return;
        Sum += root->val;
        if(m.find(Sum - targetSum)!= m.end())total+=m[Sum - targetSum];
        m[Sum]++;
        helper(root->left , targetSum , m , Sum);
        helper(root->right , targetSum , m , Sum );
        m[Sum]--;
        
    }
    
    
    
    int pathSum(TreeNode* root, int targetSum){
        if(root ==NULL )return  0;
        map<int ,int > m ;
        m[0] = 1;
        helper(root , targetSum , m, 0);
        return total;
        
    }