#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node * left; // 0
    node * right; // 1
};
class trie{
    public:
    node * root;
    

    trie(){
        root = new node();
    }
    
    void insert(int n){
        node * temp =root;
        // bits of that no. in the trie
        for(int i = 31 ; i>=0; i--){
            int bit = (n>>i)&1; // bit masking
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }else{
                if(temp ->right == NULL){
                    temp ->right = new node();
                }
                temp = temp->right;
            }
        }
    }
     int xor_helper(int value){
        int current_ans =0;
        node * temp =root;
        for(int j =31 ; j>=0 ; j--){
            int bit = (value>>j)&1; 
            if(bit == 0){
                // look for 1
                if(temp ->right!= NULL){
                temp =temp ->right;
                current_ans += (1<<j);
                 }
                else{
                    temp = temp->left;
                }}
             else{
                    // look for 0
                    if(temp->left !=NULL){
                        temp= temp->left;
                        current_ans +=(1<<j);
                    }
                    else{
                        temp =temp->right;
                    }
                }
            }

            return current_ans;
        }
        
        
    int Max_xor(int *input , int n){

        int max_xor = 0;
        for(int i =0 ; i<n ; i++){
            int value = input[i];
            insert(value);
            int current_xor = xor_helper(value);
             max_xor = max(max_xor, current_xor);

        }
          return max_xor;

   
     }

        
};
int main(){
    int input [] = {3,10,5,25,9,2};
    int n = sizeof(input)/sizeof(int);
    trie t;

    cout << t.Max_xor(input , n)<< endl;
}