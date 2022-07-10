#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int key;
    Node * left;
    Node * right;
    Node(int key){ // key == data
        this -> key = key;
        left = right = NULL;
    }
};

Node * Insert(Node * root , int data){
    //base
    if(root == NULL){
        return new Node(data);
    }        
    // rec case
    if(data < root -> key){
        root ->left = Insert(root ->left , data);

    }
    else{
        root ->right = Insert(root ->right , data);
    }
    
}
// BST to linked list



void printInOrder(Node * root ){
    if(root == NULL){
        return;
    }
    printInOrder(root ->left);
    cout << root ->key<< ",";
    printInOrder(root ->right);
}

Node * inorderSucc(Node* root , Node *target){
    if(target ->right !=NULL){
        Node *temp =target ->right;
        while(temp ->left!= NULL){
            temp =temp->left;
        }
        return temp;
    }

    // otherwise
    Node *temp = root;
    Node *succ =NULL;
    while(temp!=NULL){
        if(temp ->key >target ->key){
            succ =temp;
            temp = temp ->left;
        }
        else if(temp ->key <target ->key){
            temp = temp ->right;
        }
        else {
            break;
        }
    }
    return succ;
}



 int main(){
     Node * root = NULL;
    root = Insert(root ,8);
    root = Insert(root ,3);
    root = Insert(root ,10);
    root = Insert(root ,1);
    root = Insert(root ,6);
    root = Insert(root ,14);
    root = Insert(root ,4);
    root = Insert(root ,7);
    root = Insert(root , 13);

    Node * t1 = root ->left ->right ->right;
    Node *t2 = root ->right;
    cout << inorderSucc(root ,t1) ->key <<endl;
    cout << inorderSucc(root , t2)->key << endl; 
    }

 