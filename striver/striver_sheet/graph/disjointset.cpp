#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[10000000];



void makeSet()
{
for(int i= 1; i<=n ; i++)
{
    parent[i] = i;
    rank[i] = 0;
}






}

int findPar(int node){

    if(node == parent[node]){
        return node;
    }
    return parent[node] = findPar(parent[node]);






}
void Union(int u , int v)
{
    u = findPar(u);
    v = findPar(v);
    
    
    if(rank[u]< rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;

    }else{
        parent[v] = u;
        rank[u]++;
    }







}










void main(){




}