bool ispossible(int n , int m , vector<int> time , long long mid){
    int day = 1;
    long long timeta = 0;
    for(int i = 0; i< m; i++){
        if(time[i]>mid)return false;
        if(timeta + time[i] <= mid){
            timeta += time[i];
        }
        else{
            day +=1;
            timeta = time[i];
        }
        if(day > n)return false;
    }
    
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long low = 0;
    long long high  =0;
    for(int i = 0; i< time.size() ;i++){
        high += time[i];
    }
    long long ans  = -1;
    while(low <= high){
        long long mid = (low + high) >> 1;
        if(ispossible(n,m,time, mid)){
            high = mid -1;
            ans = mid;
        }else{
            low = mid+1;
        }
           
        
        
        
        
        
    }
    
    return ans;
    
    
}