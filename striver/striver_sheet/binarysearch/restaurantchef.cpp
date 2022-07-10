#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t ;
	 cin >> t;
	 while(t--){
	     int n , m;
	     cin >> n >> m;
	     vector<pair <int ,int>> intervals;
	     for(int i = 0; i< n ;i++){
	         int start , end;
	         cin >> start >> end;
	         intervals.push_back(make_pair(start ,end));
	         
	     }
	     sort(intervals.begin() , intervals.end());
	     while(m-- ){
	         int curr;
	         cin >> curr;
	         int position= lower_bound(intervals.begin(), intervals.end() , make_pair(curr, 0))- intervals.begin();
	         if(position == 0){ // when  curr matches wiht 0 position
	             int ans = intervals[0].first - curr;
	             cout  << ans << endl;
	         }else{
	             
	             int ans = -1; // for outof bound
                 
                 // comparing wiht just nefore this posti
	             if(intervals[position -1 ].second > curr){
	                 ans = 0;
	             }else if(intervals.size() > position){ // position lies in intercals
	                 ans = intervals[position].first - curr;
	             }
	             cout << ans << endl;
	             
	             
	         }
	         
	         
	     }
	     
	     
	     
	     
	     
	 }
	
	
	return 0;
}
