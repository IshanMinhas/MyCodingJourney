#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
we r returning a vec ans . and root == nuyll we retu empty vec . if not we use rec to iterate thru the tree to find 
the node. we push the node into the ans vector. and then if node is equal to the node req then we return 
if not
we go to the children left and right of node
if the children are not present that is leaf nofe htne we return falseesle return truel
if req node is not found return flse;
for return flse we also add a cond thfor leaf node in the beginning


*/
bool helper(TreeNode * root, int a ,vector<int > &ans){

    if(!root)return false;
    arr.push_back(root->val);
    if(root ->val== a)return true;
    if(helper(root->left ,a , ans)  || helper(root ->right , a ,ans ))return true;
    arr.pop_back();
    return false;






}
vector<int> path(TreeNode * root , int a){
    vector<int > ans;
    if(root == NULL) return ans;
    helper(root , a , ans);
    return ans;


}