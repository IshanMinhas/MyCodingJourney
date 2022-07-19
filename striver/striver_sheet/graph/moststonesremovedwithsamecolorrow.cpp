class DSU {
public:
	vector<int> parent, size;
	DSU(int n) {
		for (int i = 0; i < n; i++) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);
        unordered_map<int , vector<int > > rowmp , colmp ;
        
        for(int i=0;i<n;i++){
            rowmp[stones[i][0]].push_back(i);
            colmp[stones[i][1]].push_back(i);
        }
        
        for(int i=0;i<n;i++){
            for(auto it : rowmp[stones[i][0]])dsu.unionSize(i , it);
            for(auto it : colmp[stones[i][1]])dsu.unionSize(i , it);
        }
        unordered_set<int > set;
        for(auto i : dsu.parent)set.insert(dsu.findPar(i));
        return n - set.size();
    }
};
static const auto speedup =[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();