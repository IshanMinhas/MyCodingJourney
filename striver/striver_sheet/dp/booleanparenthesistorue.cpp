int mod  = 1000000007 ;
long long f(int i , int j , int isTrue ,string & a ,vector<vector<vector<long long>>> &dp ){
	long long ways = 0;
	if(i > j) return 0;
	if(i == j){
		if(isTrue) return (a[i] == 'T');
		else return (a[i] == 'F');
	}
	if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
	
	for(int ind = i+1 ; ind <= j-1 ; ind+= 2){
		long long LT = f(i , ind- 1, 1, a, dp)%mod;
		long long LF = f(i, ind-1, 0 ,a, dp)%mod;
		long long RT = f(ind+1 ,j , 1 , a, dp)%mod;
		long long RF =f(ind+1, j, 0,a, dp)%mod;
		
		if(a[ind] == '&'){
			if(isTrue){
				ways =(ways +  (LT*RT)%mod)%mod;
			}
			else{
				ways = (ways + (LF*RT)%mod + (LF*RF)%mod + (LT*RF)%mod  )%mod;
			}
		}
		
		else if(a[ind] == '|'){
			if(isTrue){
				ways = (ways + (LF*RT)%mod + (LT*RT)%mod + (LT*RF)%mod) %mod;
			}
			else{
				ways =(ways + (LF*RF)%mod)%mod;
			}
		}
		
		else if(a[ind] == '^'){
			if(isTrue){
				ways = (ways + (LF*RT)%mod  + (LT*RF)%mod )%mod;
			}
			else{
				ways = (ways + (LF*RF)%mod + (LT*RT)%mod) %mod;
			}
			
			
		}
		
		
		
	}
	return dp[i][j][isTrue] = ways;
	
	
	
	
	
	
	
}


int evaluateExp(string & exp) {
    // Write your code here.
	int n = exp.size();
	vector<vector<vector<long long>>> dp(n , vector<vector<long long>> (n ,vector<long long> (2 , -1)));
	return f(0 , n- 1, 1 , exp, dp);
}