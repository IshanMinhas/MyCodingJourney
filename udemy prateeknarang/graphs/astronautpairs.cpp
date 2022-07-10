#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<queue>
using namespace std;

class Graph{
	list<int> *l;
	int V;
public:
	
    
    
    
    
    
    Graph(int v){
		V = v;
		//Array of Linked List
		l = new list<int>[V];
	}

	
    
    
    
    
    void addEdge(int i,int j,bool bidir=true){
		l[i].push_back(j);
		if(bidir){
			l[j].push_back(i);
		}
	}
	
    
    
    
    
    
    int traverseHelper(int s,bool *visited){
		visited[s] = true;
		int size = 1;

		//visit the neighbours of s and thier neighbours recursilvely
		for(int nbr:l[s]){
			if(!visited[nbr]){
				size += traverseHelper(nbr,visited);
			}
		}
		return size;
	}
	//DFS - Depth First Search O(V+E) Linear
	
    
    
    
    
    
    
    
    int countAstronauts(){
		bool *visited = new bool[V]{0};
		int ans = V*(V-1)/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){

				
				 int csize = traverseHelper(i,visited);
				 ans -= (csize)*(csize-1)/2;
				 
			}
		}
		return ans;
	}

};








int count_pairs(int N, vector<pair<int,int> > astronauts){
    //complete this method
    Graph g(N);
    
    for(auto edge : astronauts){
        g.addEdge(edge.first,edge.second);
    }
    
    return g.countAstronauts();
}
int main(){
	int NoofAstronauts = 5;
	vector<pair<int,int> > astronauts = { { 0 ,1} , {1,4} , {2,3}};
	cout << count_pairs(NoofAstronauts , astronauts) << endl;

}