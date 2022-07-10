#include<iostream>
#include<bits/stdc++.h>
using namespace std;



// trie and hashing














class Node{
    public:
    char data;
    unordered_map<char ,Node *> children;
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
            if(temp->children.count(ch) == 0){
                Node * Newchar = new Node(ch);
                temp->children[ch] = Newchar;
            }
            temp = temp->children[ch];
        }
        temp->isTerminal =true;
    }
};
void helperSearch(Trie t, string document, int i, unordered_map<string, bool> &m){
    Node * temp = t.root;
    for(int j =i ; j<document.length(); j++){
        char ch = document[j];
        if(temp ->children.count(ch) == 0){
            return;
        }
        temp = temp->children[ch];
        if(temp ->isTerminal){
            string out = document.substr(i,j-i+1);
            m[out] = true;
        }
    
    }
    return;
}
void documentSearch(string document , vector<string> words){
    // create trie and insert words
    Trie t;
    for(auto w :words){
        t.insert(w);
    }
    //2. search 
    unordered_map<string, bool> m; // to mark the words found so far
    for(int i = 0 ; i<document.length(); i++){
        helperSearch(t, document, i, m);
    }

    // 3 check if they are presernt in map or not
    for(auto w :words){
        if(m[w]){
            cout << w << "true"<< endl;

        }
        else{
            cout << w<< "false"<< endl;
        }

    }






return;



}

int main(){
    string document= "little cute cat loves to code in C++ , Java and Python";
    vector<string >words = { "cute cat", "ttle", "cat", "quick", "bid"};
    documentSearch(document, words);
    
}