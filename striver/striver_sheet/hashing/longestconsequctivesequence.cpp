// can be solvesd with dfs/bfs

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash;
        int n = nums.size();
        for(int num :nums   ) hash.insert(num);
        int lcs = 0;
        for(int num  :nums){
           
            
            if(!hash.count(num - 1)){
                int streak= 1;
                int currentele = num;
                while(hash.count(currentele + 1)){
                    streak+= 1 ;
                    currentele+= 1;
                }
                lcs = max(lcs ,streak);
            }
        
        
        
        }   
        return lcs;
        
    }
};