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
class LinkedList{
    public:
    Node * head;
    Node * tail;
};

LinkedList BSTTOLinkedList(Node * root){
    LinkedList l;
    // base
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    //4 cases

    if(root ->left == NULL and root->right == NULL){
        l.head = l.tail = root;
    }
    else if(root ->left!= NULL and root ->right == NULL){
        LinkedList LList = BSTTOLinkedList(root ->left);
        LList.tail ->right = root;
        l.head = LList.head;
        l.tail = root;
    }
    else if(root -> left == NULL and root ->right != NULL){
        LinkedList Rlist = BSTTOLinkedList(root ->right);
        root ->right = Rlist.head;
        l.head = root;
        l.tail = Rlist.tail;
    }
    else{
         LinkedList LList = BSTTOLinkedList(root ->left);
         LinkedList Rlist = BSTTOLinkedList(root ->right);
        LList.tail ->right = root;
        root ->right = Rlist.head;
        l.head = LList.head;
        l.tail = Rlist.tail;



    }

return l;


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
    // vector <int> arr{2,3,5,5,9,4,3,};
    // int n =arr.size();
    int a[]  =  {8,3,10,1,6,14,4,7,13 };
    for(int data : a){
    root = Insert( root, data );
      }
    // printInOrder(root);
    // sortedArrMinHeightTree(arr ,0 ,n-1);
    LinkedList l = BSTTOLinkedList(root);
    Node * temp = l.head;
    while(temp != NULL){
        cout << temp->key<< "";
        temp = temp ->right;
    }

 }