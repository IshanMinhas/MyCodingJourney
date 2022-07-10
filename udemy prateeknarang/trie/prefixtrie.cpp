#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    unordered_map<char ,Node *> m;
    bool isTerminal;
    // constructor
    Node(char d){
        data = d;
        isTerminal =false;
        // keeping the map is empty in the start by default
    }
};
class Trie{
    public:
    Node * root; // pointer
    Trie(){// when Trie objext is created then it will contain null data , false isTerminal  and empty map
        root = new Node('\0'); 
    }
    void insert(string word){
        Node* temp =root;
        for(char ch : word){
            if(temp->m.count(ch) == 0){
                Node * Newchar = new Node(ch);
                temp->m[ch] = Newchar;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal =true;
    }
    bool search(string word){
        Node *temp = root;
        for(char ch:word){
        if(temp->m.count(ch) == 0){
            return false;
        }
        temp = temp->m[ch] ;
    }
    return temp->isTerminal;
    
    }
};

int main(){
    string words[] = { "apple"  , "ape", "no" , "news" , "not" , "never"};
    Trie t;
    for(auto w: words){
        t.insert(w);
    }
    int q; // take input for no. of queries
    cin >> q;
    string search_word;
    while(q--){ // each query
        cin >> search_word;
        if(t.search(search_word)){
            cout << "yes"<<endl ;
        }
        else{
            cout << "no"<<endl;
        }
    }

}