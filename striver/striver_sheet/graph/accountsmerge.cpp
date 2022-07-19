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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);    
        vector<vector<string >> ans;
        unordered_map <string , int > emailtoid ; 
        
        // we are trying to make a union of the accounts below which have the same emails and we do this by adding all the emails of account[i] in the map and checking if they were aready present or not and if they were then we do the union of those accounts
        
        for(int i=0;i<n; i++ ){
            auto acc = accounts[i];
            for(int j= 1;j<accounts[i].size(); j++){
                if(emailtoid.find(acc[j])== emailtoid.end()){
                    emailtoid[acc[j]] = i;
                }else{
                    dsu.unionSize(i , emailtoid[acc[j]]) ; 
                }
           }          
        }
        
        // we create a map of indices which are accounts[i]th indices and all emails associated with it cuz there might be some union cases from the above piece of code and we take set of strings to avoid repiition of emails in the map and to also arrange them lexicographically
        map<int , set <string>> mpp;
        for(auto it : emailtoid){
            mpp[dsu.findPar(it.second)].insert(it.first);
        }
        // resultant vec
        for(auto it : mpp){
            vector<string > ansrow ; 
            ansrow.push_back(accounts[it.first][0]);
            for(auto i : it.second){
                ansrow.push_back(i);
            }
            ans.push_back(ansrow);
        }     
        return ans;
        
    }
    
};