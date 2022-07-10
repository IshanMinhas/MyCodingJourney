#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define M 3 // defining M, N as constant but can also take them as input
#define N 4
// USE TRIE AND DFS AND HASHING


// 1st trie
class Node{
    public:
    char s;
    unordered_map<char , Node*> children;
    string word;
    bool isTerminal;
    Node(char s){
        this->s =s;
        isTerminal = false;
        word = "";
        // we will update the word at only the leaf node nd keep it empty otherwise
    }
};
class Trie{
       public:
    Node * root;
    Trie(){
        root = new Node('\0');
    }
    
    void addWord(string word){
    
    Node * temp =root;
    for(auto ch : word){
        if(temp->children.count(ch) == 0){
            temp->children[ch] = new Node(ch);
        }
        temp = temp->children[ch];

    }
    // last node
    temp->isTerminal = true;
    temp->word = word;
    }
};

// main algo 8 way dfs and trie guided search
void dfs(char board[M][N] , Node * node, int i, int j , unordered_set<string> &output , bool visited[][N] ){
    // base case
    char ch = board[i][j];
    if(node->children.count(ch) == 0){
        return;
    }
    // rec
    visited [i][j] = true;
    node = node->children[ch];
    if(node->isTerminal== true){
        output.insert(node->word);
    // we are not going to return bcz we have to go deeper in tree aswell
    }

    int dx[] = { 0, 1, 1, 1,0, -1 , -1, -1};
    int dy[] = { -1,-1, 0, 1,1,1,0,-1};
    for(int k = 0 ; k<8 ; k++){
        int newi = i+ dx[k];
        int newj = j+ dy[k];
        if(newi >=0 and newj >=0 and newi< M and newj< N and !visited[newi][newj]){
            dfs(board , node , newi , newj , output , visited);
        }
    }
    // backtracking
    visited[i][j] = false;
    return;
}

int main( ) {
    string words[] = {
    "SNAKE", "FOR" , "QUEZ" , "SNACK" ,"SNACKS" , "GO", "TUNES" ,"CAT" };
    char board[M][N] = {
        {'S' , 'E' , 'R' , 'T'},
        {'U', 'N' ,'K' , 'S'},
        {'T' , 'C', 'A', 'T'}
        };

    Trie t;
    for(auto word : words){
        t.addWord(word);
    }


    unordered_set<string> output; // to  avoid replicas
    bool visited[M][N] = {0};

    for(int i= 0 ; i<M ; i++){
        for(int j = 0 ; j<N; j++){
            dfs(board ,t.root, i,j,output , visited);
        }
    }

    // print 
    for(auto word : output){
        cout << word << endl;
    }


}
