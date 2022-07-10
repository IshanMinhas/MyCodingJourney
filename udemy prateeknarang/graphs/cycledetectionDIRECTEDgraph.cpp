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
    void addEdges(int i , int j ,bool undir= false){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    bool dfs(int node , vector<bool>&visited , vector<bool> &stack){
        // arriving at the node
        visited[node] = true;
        stack[node] = true;

        // doing work
        for(auto nbr: l[node]){
            if(visited[nbr] == false){
                bool nbrFoundACycle = dfs(nbr , visited , stack);
                if(nbrFoundACycle){
                    return true;
                }
            }
            else if(stack[nbr]== true){         /// IMP *****************************************
                                                // Checks if there is a backedge or not
                return true;
            }
        }
        // going back
        stack[node] = false;
        return false;


    }
    bool cycle_detection(){
        vector <bool> visited(V, false);
        vector <bool> stack (V, false);
        for(int i = 0 ; i<V; i++){
            if(visited[i] == false){
                if(dfs(i , visited , stack)){
                    return true;
                }
            }
            
        }
        return false;
    }
    

};

int main(){
  
    Graph g(3);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,0);

  cout << g.cycle_detection() << endl;
    // g.dfs(1);

}