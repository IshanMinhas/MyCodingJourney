#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU {
private: 
	vector<int> parent, size, rank; 

	public:
    DSU(int n) {
		for(int i = 0;i<=n;i++) {
			parent.push_back(i); 
			size.push_back(1); 
			rank.push_back(0); 
		}
	}


public: 
	int findPar(int node) {
		if(parent[node] == node) {
			return node; 
		}
		// path compression -> (log n)
		// path compression and size -> O(4 x alpha)
		return parent[node] = findPar(parent[node]); 
	}

public:
	void unionSize(int u, int v) {
		int pu = findPar(u); 
		int pv = findPar(v); 
		if(pu == pv) {
			return; 
		}

		// pu chota
		// pu ko zod pv me 
		// pv bolega me bada hogaya re baba, mera size badha de
		if(size[pu] < size[pv]) {
			parent[pu] = pv; 
			size[pv] += size[pu]; 
		}
		else {
			parent[pv] = pu; 
			size[pu] += size[pv]; 
		}
	}
public:
	void unionRank(int u, int v) {
		int pu = findPar(u); 
		int pv = findPar(v); 
		if(pu == pv) {
			return; 
		}

		// pu chota
		// pu ko zod pv me 
		// pv bolega me bada hogaya re baba, mera size badha de
		if(rank[pu] < rank[pv]) {
			parent[pu] = pv; 
		}
		else if(rank[pv] < rank[pu]){
			parent[pv] = pu; 
		}
		// rank is equal, in case of equal then increase
		else {
			parent[pu] = pv;
			rank[pv]++; 
		}
	}
};
void roadsInBerland() {
	int n, m;
	cin >> n;
	m = n - 1;
	DSU dsu(n + 1);
	vector<pair<int, int>> extraRoad;
	// step 1 storage of old roads is done
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (dsu.findPar(u) == dsu.findPar(v)) {
			extraRoad.push_back({u, v});
		}
		else {
			dsu.unionSize(u, v);
		}
	}


	// figure put the number of compos
	set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(dsu.findPar(i));
	}

	int x = st.size();
	cout << x - 1 << endl;
	vector<int> vec(st.begin(), st.end());
	int j = 0;
	for (int i = 1; i <= x - 1; i++) {
		cout << extraRoad[j].first << " " << extraRoad[j].second << " " <<
		     vec[i] << " " << vec[i - 1] << endl;
		j++;
	}
}


