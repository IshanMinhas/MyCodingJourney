double mul(double mid , int n){
    double ans= 1; 
    for(int i=1; i<=  n; i++){
        ans = ans*mid;     
    }
    return ans;
}

double findNthRootOfM(int n, long long m) {
	// Write your code here.
   double lo = 1;
    double hi = m; 
    double eps = 1e-8;
    while((hi-lo) >eps){
        double mid = (lo+hi)/2.0;
        if(mul(mid ,n )< m){
            lo = mid;
        }else{
            hi = mid;
        }     
        
    }
    return lo;
    
}



//OR POWER SET
