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
    void bfs(int source, int dest =-1){
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *distance = new int[V]{0};
        int *parent = new int[V];
        for(int i =0 ; i<V ; i++){
            parent[i] = -1; // all members of parent array are initialized to -1
        }

        q.push(source);
        visited[source] = true;
        parent[source] = source;
        distance[source] =0;



        while(!q.empty()){
            int front = q.front();
            cout << front <<endl;
            q.pop();
            for(auto nbr: l[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = front;
                    distance[nbr] = distance[front] +1;
                    visited[nbr] = true;
                }
            }
        }
        // print the shortest distance
        // for(int i =0 ; i<V ; i++){
        //     cout << "shortest distance to" << i << "is"<< distance[i]<< endl;
        // }   

        // print the path from source to any destination
        if(dest!=-1){
            int temp =dest;
            while(temp!=source){
                cout << temp << "--";
                temp = parent[temp];

            }
            cout << source << endl;
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
    g.bfs(1,6);
}