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
class DSU{
private : 
        vector<int > par , size ;
        DSU(int n){
            for(int i=0;i<n;i++){
                par.push_back(i);
                size.push_back(1);
            }
        }
public : 
        int findULTParent(int node){
            if(parent[node]==node)return node;
            // path ccmpression tc= logn
            //path comp + size tc = 4*alpha as goof as constant
            return parent[node ] = findULTParent(parent[node]);
        }
public  :
        void Union(int u , int v){
            int pu = findULTParent(u);
            int pv = findULTParent(v);
            if(pu == pv){
                return;
            }
            if(size[pu] <size[pv] ){
                parent[pu] = pv;
                size[pv] += size[pv];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
}








void solve(){
    DSU dsu(n);
}




