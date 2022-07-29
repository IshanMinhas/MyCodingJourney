class Solution {
public:
    bool check(long long int mid ,vector<int>& time, int totalTrips ){
       long long int trips = 0;
        for(int i=0;i<time.size(); i++){
            trips += mid/time[i];    
        }
        if(trips >=totalTrips )return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int numofbuses = time.size();
        sort(time.begin(), time.end());
        long long int low = time[0]; long long int high = 1e14; long long int ans;
        while(low <= high){
            long long int mid = low+ (high -low ) /2; 
            if(check(mid, time , totalTrips)){
                ans = mid ;
                high = mid - 1  ;
            }else{
                low =mid +1 ;
            }
        }
        return ans;
    }
};