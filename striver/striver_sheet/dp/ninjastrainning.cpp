int f(int day , int last , vector<vector<int>> &points, vector<vector<int>> &dp){
	if(day == 0){
		int maxi = 0;
		for(int task = 0; task <3 ; task++){
			if(task != last){
				maxi =  max(maxi , points[0][task]);
			}
		}
		return maxi;
	}
	if(dp[day][last]!= -1){
		return dp[day][last];
	}
	
	
	int maxi = 0;
	for(int task = 0; task<3 ; task++){
		if(task != last){
			int point = points[day][task] + f(day-1 , task , points, dp);
			maxi = max(maxi , point);	
		}
	}
	return dp[day][last] = maxi;
	
	
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector<vector<int>> dp(n , vector<int> (4 , -1));
	dp[0][0] = max(points[0][1] , points[0][2]);	
	dp[0][1] = max(points[0][0] , points[0][2]);
	dp[0][2] = max(points[0][1] , points[0][0]);
	dp[0][3] = max(points[0][1] , max(points[0][2] , points[0][0]));
	
	for(int day = 1 ;day< n	 ; day++){
		for(int last = 0; last<4 ; last++){
			dp[day][last] = 0;
			for(int task = 0; task<3 ; task++){
				if(task != last){
					int point = points[day][task] + dp[day-1][ task] ;
					dp[day][last] = max(dp[day][last] , point);	
				}
			}
			
		}
	}
	
	
	
	return dp[n-1][3] ;

}

// space

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector<int> dp(4 , 0);
	dp[0] = max(points[0][1] , points[0][2]);	
	dp[1] = max(points[0][0] , points[0][2]);
	dp[2] = max(points[0][1] , points[0][0]);
	dp[3] = max(points[0][1] , max(points[0][2] , points[0][0]));
	
	for(int day = 1 ;day< n	 ; day++){
        vector<int > temp(4 ,0);
		for(int last = 0; last<4 ; last++){
			temp[last] = 0;
			for(int task = 0; task<3 ; task++){
				if(task != last){
					int point = points[day][task] + dp[task] ;
					temp[last] = max(temp[last] , point);	
				}
			}
            
			
		}
        dp = temp;
	}
	
	
	
	return dp[3] ;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector<vector<int >> dp(n , vector<int > (4 , 0));
	dp[0][0] = max(points[0][1], points[0][2]);
	 dp[0][1] = max(points[0][0], points[0][2]);
	 dp[0][2] = max(points[0][1], points[0][0]);
	 dp[0][3] = max(points[0][1], max(points[0][0],  points[0][2]));

	for(int i=1; i<n; i++){
		for(int j = 0;j<=3; j++){
			int maxi = 0;
			for(int task = 0; task<3 ; task++){
				if(task != j){
					int point = points[i][task] + dp[i-1][task ];
					maxi = max(maxi , point);	
				}
			}
		 dp[i][j] = maxi;
		}
	}
	return dp[n-1][3];
}


