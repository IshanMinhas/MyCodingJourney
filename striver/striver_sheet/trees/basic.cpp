#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
     Node * left;
     Node * right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int main(){

// Node * root = new Node(1);
// root ->left = new Node(2);
// root ->right = new Node(3);
// root ->left ->right = new Node(4);

    int ans[][];
    if(!root)return ans;
    stack<Node * > st;
    while(true){
        if(root){
            st.push(root);
            root = root->left;
        }else{
            if(st.empty() == true)break;
            Node * temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            root = root->right;
        }
    }


}



