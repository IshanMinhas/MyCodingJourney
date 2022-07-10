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

Node * sortedArrMinHeightTree(vector<int> arr  , int start ,int end){
    if(start >end){
        return NULL;
    }
    
    int mid = (start +end)/2;
    Node * root = new Node(arr[mid]);
    root ->left = sortedArrMinHeightTree(arr , start , mid-1);
    root ->right = sortedArrMinHeightTree(arr , mid+1 ,end);
    
    return root;
}



 int main(){
    //  Node * root = NULL;
    vector <int> arr{2,3,5,5,9,4,3,};
    int n =arr.size();
    //  int a[]  =  {8,3,10,1,6,14,4,7,13 };
    //  for(int data : a){
    //      root = Insert( root, data );
    //  }
    // printInOrder(root);
    sortedArrMinHeightTree(arr ,0 ,n-1);

 }