#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;
    public:
    Graph(int v){
        V = v;
        l = new list<int>[V+1];
    }
    void addEdges(int i , int j ){
        l[i].push_back(j);
    }
    int bfs(int source, int dest =-1){
        queue<int> q;
        /*vector<bool> visited(V ,false);
        vector<int> distance(V,0);
        */
        bool *visited = new bool[V]{0};
        int *distance = new int[V]{0};
      
        q.push(source);
        visited[source] = true;
        distance[source] =0;

        while(!q.empty()){
            int front = q.front();
            cout << front <<endl;
            q.pop();
            for(auto nbr: l[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    distance[nbr] = distance[front] +1;
                    visited[nbr] = true;
                }
            }
        }
        return distance[dest];
    }
};


int min_dice_throws(int n , vector<pair<int ,int>> snakes , vector<pair <int,int>> ladders){
    vector <int> board(n+1,0);
    for(auto sp :snakes){
        int s =sp.first;
        int e = sp.second;
        board[s] = e-s;
    }
    for(auto lp: snakes){
        int s = lp.first;
        int e = lp.second;
        board[s] = e-s;

    }
    Graph g(n+1);
    for(int i = 1; i<n; i++){
        for(int dice =1 ; dice<=6 ; dice++){
            int v = i + dice;
            v +=board[v];
            if(v <= n){
                g.addEdges(i,v);
            }
        }
    }
    return g.bfs(1,n);
}




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