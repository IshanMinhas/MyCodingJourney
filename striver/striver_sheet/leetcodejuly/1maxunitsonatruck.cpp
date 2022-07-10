class Solution {
public:  
    static bool sortcol(  vector<int>& v1,
                vector<int>& v2 ) {
            return v1[1] > v2[1];
        }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end(), sortcol); 
        int ans = 0 ; 
        
            for(int i = 0; i<boxTypes.size(); i++){
                while(boxTypes[i][0] && truckSize > 0 ){
                    truckSize--; boxTypes[i][0] --;
                    ans+= boxTypes[i][1];
                }
            }
        return ans;
       
    }
};