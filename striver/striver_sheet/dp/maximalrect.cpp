#include<bits/stdc++.h>
int solve(vector<int>&a,int n){
	int ans=0;
	vector<int>ls(n);
	vector<int>rs(n);
	stack<int>s;
	for(int i=0;i<n;i++){
		while(!s.empty() && a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty()){
			ls[i]=0;
		}
		else{
			ls[i]=s.top()+1;
		}
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && a[s.top()]>=a[i]){
			s.pop();
		}
		if(s.empty()){
			rs[i]=n+1;
		}
		else{
			rs[i]=s.top()+1;
		}
		s.push(i);
	}
	for(int i=0;i<n;i++){
		ans=max(ans,(rs[i]-ls[i]-1)*a[i]);
	}
	return ans;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int ans=0;
	vector<int>a(m);
	for(int i=0;i<m;i++){
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0){
				a[j]=0;
			}
			else{
				a[j]+=mat[i][j];
			}
		}
		int k=solve(a,m);
		ans=max(ans,k);
	}
	return ans;
}