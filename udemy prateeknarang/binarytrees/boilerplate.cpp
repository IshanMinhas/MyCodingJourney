#include<iostream>
#include<                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                bits/stdc++.h>
using namespace std;

class node{
    public:
    int data ;
    node *left;
    node*right;

    node(int d){
        data =d;
        left = right =NULL;
    }
};
//-----------------------------------------------------------------------------------------------





node * buildTree(){
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    int d;

    cin >> d;
    if(d == -1){
        return NULL;
    }
    node * n =new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}
//--------------------------------------------------------------------------------------------------------







void levelOrderPrint( node * root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        if(temp == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<< temp->data<< "";
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;

}
//----------------------------------------------------------------------------------------





node * levelOrderBuild(){
    int d;
    cin >> d;
    node * root = new node(d);
    queue< node *> q;
    q.push(root);
    while(!q.empty()){
        node * current= q.front();
        q.pop();
        int c1 , c2;
        cin>> c1 >> c2;
        // the null case is handled bcz of the constructor fnc as when a new node is formed it is NULL by defualt
        if(c1 != -1){
            current->left = new node(c1);
            q.push(current->left);
        }
        if(c2!= -1){
            current->right = new node(c2);
            q.push(current->right);
        }
    }
    return root;
}
//-------------------------------------------------------------------------------------------------
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+max(h1 ,h2);
}

//---------------------------------------------------------------------------------------------------



 int diameter(node *root){
     // base
        if(root == NULL){
            return 0;
        }   
     //rec
     int D1 = height(root->left) +height(root ->right); 
     int D2 = diameter(root ->left);
     int D3 = diameter(root ->right);
     return max(D1 , max(D2 ,D3));
 }
// optimised diameter
class HDpair{
    public :
    int height ;
    int diameter ;
};
    HDpair optDiameter(node * root){
        HDpair p;
        if(root == NULL){
            p.height = p.diameter =0;
            return p;
        }
        HDpair Left = optDiameter(root->left);
        HDpair Right = optDiameter(root -> right);
        p.height = max(Left.height  ,Right.height)+1;
        int D1 = Left.height + Right.height;
        int D2 = Left.diameter;
        int D3 = Right.diameter;
        p.diameter = max(D1 , max(D2 , D3));
        return p;
    }

int replaceWithSum(node * root){

    //base
    if(root == NULL ){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return root->data;
    }

    //rec

    int LS = replaceWithSum(root ->left);
    int RS = replaceWithSum(root ->right);
    int temp = root->data;
    root ->data = LS +RS;
    return root->data + temp;
}

pair<int , bool> isHeightBalanced( node *root){
    //O(n) time PostOrder Traversal
    pair<int , bool> p ,Right, Left;
    if(root == NULL){
        p.first = 0;
        p.second = true;
    }
    Left = isHeightBalanced(root ->left);
    Right = isHeightBalanced(root ->right);

    int height = max(Left.first  , Right.first) +1;
    if(abs(Left.first - Right.first)<= 1 and Left.second and Right.second){
        return make_pair(height ,true);
    }
    return make_pair(height ,false);


}
class Pair{
    public:
    int inc;
    int exc;
};
Pair maxSubsetSum(node *root){
    Pair p;
    // base
    if(root == NULL){
        p.inc = p.exc =0;
        return p;
    }
    // rec
    Pair Left = maxSubsetSum(root ->left);
    Pair Right = maxSubsetSum(root ->right);
    p.inc = root ->data + Left.exc + Right.exc;
    p.exc = max(Left.inc , Left.exc) + max(Right.inc , Right.exc);
    return p;
    }



//---------------------------------------------------------------------------------------
void printAtLevelK(node *root , int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << "";
        return;
    }
    printAtLevelK(root -> left , k-1);
    printAtLevelK(root ->right , k-1);
    return;
}




//--------------------------------------------------------------------------------------
// PRINT NODES AT DISTANCE K
int printNodesAtDistanceK (node * root , node *target , int k){
    // base c
    if(root == NULL){
        return -1;
    }
    // if target is present
    if(root == target){
        // comparing pointers
        printAtLevelK(target ,k);
        return 0;// as we are standing ont the target
        
    }
    int DL = printNodesAtDistanceK(root ->left , target ,k);
    if(DL != -1){
        // 2cases
        // check for root
        if(DL +1 == k){
            cout << root ->data;
        }
        // check for right subt
        else{
            printAtLevelK(root ->right , k-2-DL);

        }
        return 1+DL;
    }
       int DR = printNodesAtDistanceK(root ->right , target ,k);
    if(DR != -1){
        // 2cases
        // check for root
        if(DR +1 == k){
            cout << root ->data;
        }
        // check for right subt
        else{
            printAtLevelK(root ->left , k-2-DR);

        }
        return 1+DR;
    }
    return -1;

    }



//---------------------------------------------------------------------------------------
// VERTICAL ORDER PRINT
//helper
void traverseTree(node * root , int d ,map<int ,vector<int>> &m){//key is int distance passed by ref as we dont want to  make multiple copies of the map
    if(root == NULL){
        return;

    }
    m[d].push_back(root ->data);
    traverseTree(root ->left, d-1 , m);
    traverseTree(root ->right , d+1 , m);
}
void verticalOrderPrint(node * root){
    int d = 0;
    map<int ,vector<int>> m;
    traverseTree(root , d, m);
    // keys are sorted in map
    for(auto p:m){
        int key = p.first;
        vector<int> x = p.second;
        for(auto data: x ){
            cout << data << "";
        }
        cout <<endl;

    }
    return;
}














//--------------------------------------------------------------------------------
// LEFT VIEW




// #include<bits/stdc++.h>
// using namespace std;

// class Node
// {
//   public:
//    int key;
//    Node *left;
//    Node *right;

//    Node(int key){
//        this->key = key;
//        left = right  = NULL;
//    }
// };



// int max_level = 0;
// void leftViewUtil(vector<int>& vec, Node* root, int level)
// {
//     // base case
//     if (root == NULL)
//         return;
 
//     // If this is the first node of its level
//     if (max_level < level) {
//         vec.push_back(root->key);
//         max_level = level;
//     }
 
//     // Recur for left and right subtrees
//     leftViewUtil(vec, root->left, level + 1);
//     leftViewUtil(vec, root->right, level + 1);
// }
 
// // Function to get the left view
// vector<int> leftView(Node* root)
// {
//     max_level = 0; // initialise max_level with 0 here
//     vector<int> vec;
//     // calling util function
//     leftViewUtil(vec, root, 1);
//     return vec;
// }









//------------------------------------------------------------------------------------------
//SIBLINGS SWAP
// #include<bits/stdc++.h>
// using namespace std;

// class Node
// {
//   public:
//    int key;
//    Node *left;
//    Node *right;

//    Node(int key){
//        this->key = key;
//        left = right  = NULL;
//    }
// };


// bool equal(Node * X, Node * Y){
//     //Complete the Function
//     if (X == Y) {
//         return true;
//     }
//     return (X && Y) && (X->key == Y->key) &&
//         ((equal(X->left, Y->left) && equal(X->right, Y->right)) ||
//         (equal(X->right, Y->left) && equal(X->left, Y->right)));
    
// }

















//------------------------------------------------------------------------------

int main(){
    // node * root =buildTree();
    // // node * root = levelOrderBuild();
    // levelOrderPrint(root);
    // // cout << endl;
    // // replaceWithSum(root);
    // // levelOrderPrint(root);
    // // cout<< diameter(root) << endl;
    // // cout << optDiameter(root).diameter << endl;
    // Pair p = maxSubsetSum(root);
    // cout << "max subset sum "<< max(p.inc , p.exc)<< endl;
    //    int k =2;
    // printNodesAtDistanceK(root ,target ,k);
    // cout << endl;
    // node * root =new node(1);
    // root ->left = new node(2);
    // root ->right = new node (3);
    // root ->left ->left = new node(4);
    // root -> left ->right = new node(5);
    // root -> right ->right = new node(6);
    // root ->left ->right ->left  = new node (7);
    // root -> left -> right ->right = new node(8);
    // root -> right ->right ->right ->right =new node(10);
    // node * target = root ->left ->right;
    

     node * root =new node(1);
     root ->left = new node(2);
     root ->right = new node (3);
     root ->left ->left = new node(4);
     root -> left ->right = new node(5);
     root -> right ->left = new node(6);
     root ->right ->right  = new node (7);
     root -> right ->left ->right = new node(8);
     root -> right-> right ->right = new node(9);
     verticalOrderPrint(root);
    



}