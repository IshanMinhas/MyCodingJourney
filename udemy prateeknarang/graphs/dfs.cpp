#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;
    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdges(int i , int j ,bool undir= true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    
    void dfs_helper(int node , bool * visited){
        visited[node] = true;
        cout << node <<"," <<endl;
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                dfs_helper(nbr , visited);
            }
        }
        return;
    }
    
    void dfs( int source){                                  // wrapper function for helper
        // visited arr can only be made once otherwise it wont get updated
        bool *visited = new bool[V]{0};
        dfs_helper(source , visited);
    }

};

int main(){
    // Output depends on what order the inputs have been given 
    // interchange the neibrs order to see the diff
    Graph g(7);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(5,6);
    g.addEdges(3,5);
    g.addEdges(4,5);
    g.addEdges(0,4);
    g.addEdges(3,4);
    g.dfs(1);

}