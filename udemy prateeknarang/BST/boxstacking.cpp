#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// less than operator should remain the same in both fncs or greater than in both fncs
bool compare(vector<int> b1 , vector<int> b2){
    return b1[2] < b2[2];
}

bool CanPlace(vector<int> b1 , vector<int> b2){
    if(b1[0] < b2[0] and b1[1] < b2[1] and b1[2] < b2[2]) //comparing ht cuz 2 boxeds can have same ht in sortes ar r but we need less ht while stacking for boxes on top
    {
         return true;
    }
  
}


int height(vector <vector< int> > boxes){

    int n = boxes.size();
    sort(boxes.begin() , boxes.end(), compare);
    
    
    vector< int> dp(n+1 , 0);
    
    for(int i = 0; i<n; i++){
        dp[i] = boxes[i][2];
    }
    
    
    int maxht = 0;
    for(int i = 1 ; i< n; i++){
        for( int j =0 ; j< n ; j++){
            if(CanPlace(boxes[j] , boxes[i])){
                int currht = boxes[i][2];
                if(dp[j]  + currht > dp[i]){
                    dp[i] = dp[j]  + currht;
                }
                maxht = max(maxht , dp[i]); 
            }
        }
    }
    return maxht;
}

int main(){
    vector< vector<int>>  boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };
    cout << height(boxes) << endl;



}