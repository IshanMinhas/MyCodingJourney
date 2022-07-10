#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count_top_down(string a  , string b  , int n1 , int n2){

    // base 

    if(n1 == -1 and  n2 == -1){
        return 1;

    }
    if(n2 == -1){
        return 1;
    }
    if(n1 == -1){
        return 0;
    }

    // rec c

   

    if(a[n1] != b[n2]){
        return count_top_down( a ,b ,n1 - 1 , n2);

    }


    if(a[n1] == b[n2]){
        return  count_top_down(a,b , n1-1 , n2-1) + count_top_down(a,b,n1-1 , n2);
    }



    





}

int count_bottom_up(string a , string b){
    int m = a.length();
    int n =b.length();
    vector <vector<int>> dp(m +1, vector<int> (n+1 , 0));

    for(int i = 0; i<=m ; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=m ; i++){
        for(int j =1 ; j<=n ; j++){

            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

            }
            else{
                dp[i][j] = dp[i-1][j]; 
            }
            cout << dp[i][j] << "";

        }
        cout << endl;
    }


    return dp[m][n];

}



int main(){

    
    
    string a  = " ABCDCE";
    string b = "ABC";
    cout << count_top_down(a , b, a.size() - 1 , b.size() - 1) <<endl;
    cout << count_bottom_up(a,b) << endl;







}