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
    printInOrder(root);

 }


 //---------------------------------------------------------------------------------------
 