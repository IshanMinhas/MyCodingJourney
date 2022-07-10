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
 // Recursive fnc to check if there if a cycle or not
 //explanation in Nbook for the fnc

    bool dfs(int node , vector <bool> &visited , int parent){
        visited[node] = true;
        for(auto nbr :l[node]){
            if(!visited[nbr]){
                bool Nbrhasreturnedacycle = dfs(nbr , visited  , node);
                if(Nbrhasreturnedacycle){
                    return true;
                }
            }
                else if(nbr != parent){
                    return true;
                }
            }
        
        
        return false;
    }

    bool cycleDetection(){
        vector<bool> visited(V, false)    ;
        return dfs(0 , visited , -1);
    }

};

int main(){
  
    Graph g(3);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,0);
    cout << g.cycleDetection() << endl;
  
    // g.dfs(1);

}