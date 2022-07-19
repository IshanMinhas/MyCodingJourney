class DSU {
public:
	vector<int> parent, size, rank;

public:
	DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);		
		}
	}


public:
	int findPar(int node) {
		if (parent[node] == node) {
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}

public:
	void unionSize(int u, int v) {
		int pu = findPar(u);
		int pv = findPar(v);
		if (pu == pv) {
			return;
		}
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        DSU dsu(n); 
        int cnt = 0 ;
        for(auto it : connections){
            int a = dsu.findPar(it[0]);
            int b = dsu.findPar(it[1]);
            dsu.unionSize(it[0], it[1]);
            
        }
        if((n - m) > 1 )return -1;
       for(int i=0;i<n;i++){
           if(dsu.parent[i] == i)cnt++;   
           }
        return cnt-1;
    }
};