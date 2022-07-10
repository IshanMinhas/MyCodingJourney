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

    void printAllEdges(){
        //for iterating over all rows
        for(int i = 0; i<V ; i++){
            cout << i<< "-->";
            // for all elements in rows
            for( auto node: l[i]){
                cout << node<< ",";

            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(6);
    g.addEdges(0,1);
     g.addEdges(0,4);
      g.addEdges(2,1);
       g.addEdges(3,4);
        g.addEdges(4,5);
         g.addEdges(2,3);
          g.addEdges(3,5);
          g.printAllEdges();

}