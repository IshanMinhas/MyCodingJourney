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
int findClosestToTarget(Node * root , int target){
    int closest;
    int diff = INT_MAX;
    Node * temp = root;
    while(temp!= NULL){
        int current_diff = abs(temp -> key - target);
        if(current_diff == 0){
            return temp->key;
        }
        if(current_diff < diff){
            diff = current_diff;
            closest = temp ->key;
        }
        if(target >temp ->key){
            temp = temp->right;
        }
        else{temp = temp->left;}
        
    }

return closest;

}


void printInOrder(Node * root ){
    if(root == NULL){
        return;
    }
    printInOrder(root ->left);
    cout << root ->key<< ",";
    printInOrder(root ->right);
}




 int main(){
     Node * root = NULL;
     int a[]  =  {8,3,10,1,6,14,4,7,13 };
     for(int data : a){
         root = Insert( root, data );
     }
    // printInOrder(root);
    cout << findClosestToTarget(root ,17)<< endl;

 }