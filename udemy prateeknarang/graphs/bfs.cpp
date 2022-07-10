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
    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int front = q.front();
            cout << front <<endl;
            q.pop();
            for(auto nbr: l[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main(){
    Graph g(7);
    g.addEdges(0,1);
    g.addEdges(1,2);
    g.addEdges(2,3);
    g.addEdges(3,5);
    g.addEdges(5,6);
    g.addEdges(4,5);
    g.addEdges(0,4);
    g.addEdges(3,4);
    g.bfs(1);

}