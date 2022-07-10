class Solution {
public:
    #define ppi pair<int , string> 
   class myComparator{
       public : 
            bool operator()(ppi &p1,ppi &p2  ){
            if(p1.first == p2.first)return p1.second < p2.second;
            return p1.first > p2.first;
            }
   };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int > mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }
        priority_queue<ppi , vector<ppi > , myComparator > minh;
        for(auto p : mpp){
            minh.push({p.second , p.first});
            if(minh.size()> k){
                minh.pop();
            }
        }
        
        vector<string >ans(k);int m = k-1;
        while(minh.size()){
        ans[m--] = minh.top().second;
        minh.pop();        
            
        }
       
        return ans;
    }
};