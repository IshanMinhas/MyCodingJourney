class DSU {
private:
	vector<int> parent, size;

public:
	DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);		
		}
	}
	int findPar(int node) {
		if (parent[node] == node) {
			return node;
		}
		return parent[node] = findPar(parent[node]);
	}
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
    bool equationsPossible(vector<string>& equations) {
        int n = 26;
        DSU dsu(n) ;
        for(auto i :equations){
            if(i[1] != '!'){
               dsu.unionSize(int(i[0])- 'a', int(i[3])- 'a'); 
            }
        }
        
        for(auto i : equations){
            int a = dsu.findPar(int(i[0])- 'a');
            int b = dsu.findPar(int(i[3])- 'a');
            if(i[1] == '!' and a==b){
                return false;
            }        
        }
        return true;     
    }
};