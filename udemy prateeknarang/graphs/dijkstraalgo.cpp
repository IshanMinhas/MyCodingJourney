#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    list <pair<int,int>> *l;
    int V;
    public:
    Graph(int v){
        V = v;
        l = new list<pair<int,int>>[V];
    }
    void addEdges(int i , int j ,int wt , bool undir= true){
        l[i].push_back({wt,j});
        if(undir){
            l[j].push_back({wt ,i});
        }
    }
    int dijkstra(int src , int dest){
        vector <int> dist(V ,INT_MAX);
        set<pair <int , int >> s;
        // Initialize
        dist[src]=0;
        s.insert({dist[src],src });     // dist , src
        while(!s.empty()){
            auto it = s.begin();
                int node = it->second;
                int distTILLParent = it->first;


                s.erase(it); // pop
                for(auto nbrPair : l[node]){
                    int nbr = nbrPair.second;
                    int currentnbrdist = nbrPair.first;
                    if(distTILLParent + currentnbrdist < dist[nbr]){

                        if(s.find({dist[nbr], nbr}) != s.end()){
                            s.erase({dist[nbr], nbr});
                        }

                        dist[nbr] = distTILLParent + currentnbrdist;
                        s.insert({dist[nbr], nbr});
                    }
                }
        }

        for(int i = 0; i<V ; i++){
            cout << i << dist[i] << endl;
        }

        return dist[dest];

    }


};

int main(){
    Graph g(5);
    g.addEdges(0,1,1);
    g.addEdges(1,2,1);
    g.addEdges(0,2,4);
    g.addEdges(0,3,7);
    g.addEdges(3,2,2);
    g.addEdges(3,4,3);
    cout << g.dijkstra(0,4) <<endl;
  
 

}