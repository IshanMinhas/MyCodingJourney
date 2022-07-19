class DSU {
private:
	vector<int> parent, size, rank;

public:
	DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
			rank.push_back(0);
		}
	}


public:
	int findPar(int node) {
		if (parent[node] == node) {
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
		if (pu == pv) {
			return;
		}

		// pu chota
		// pu ko zod pv me
		// pv bolega me bada hogaya re baba, mera size badha de
		if (size[pu] < size[pv]) {
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
		if (pu == pv) {
			return;
		}

		// pu chota
		// pu ko zod pv me
		// pv bolega me bada hogaya re baba, mera size badha de
		if (rank[pu] < rank[pv]) {
			parent[pu] = pv;
		}
		else if (rank[pv] < rank[pu]) {
			parent[pv] = pu;
		}
		// rank is equal, in case of equal then increase
		else {
			parent[pu] = pv;
			rank[pv]++;
		}
	}
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto it : edges){
            
           int a= dsu.findPar(it[0]);
           int b=  dsu.findPar(it[1]);
           if(a==b)return {it[0], it[1]};
            
        dsu.unionSize(a, b);
        }
        return {};
    }
};