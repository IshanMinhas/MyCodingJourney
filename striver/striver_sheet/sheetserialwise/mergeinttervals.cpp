class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0){
            return result;
        }
        sort(intervals.begin() , intervals.end());
        vector<int > tempInterval = intervals[0];
        
        for(auto it : intervals){
            if(it[0] <=  tempInterval[1]){
            //merge
                tempInterval[1] = max(it[1] , tempInterval[1]);
            }
            else{
                result.push_back(tempInterval);
                tempInterval = it;
            }
            
            
            }
        result.push_back(tempInterval);
        return result;
    }
};

/*

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
   if(intervals.size() == 0)return result;
   sort(intervals.begin() , intervals.end());
   result.push_back(intervals[0]);
   for(int i =  0; i<intervals.size() ; i++){
        if(result.back()[1] >= intervals[i][0]){
            result.back()[1] = max(result.back()[1] , intervals[i][1]);
            
        }
       else{
             result.push_back(intervals[i]);
       }    
   }
    return result;
    
    
    
    
    
    
}