#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// O(LogN +P*9) = (logN)
float squareroot( int N ,int P){

    int s=0;
    int e =N;
    float ans=0;
    while(s<=e){
        int mid =(s+e)/2;
        if(mid*mid == N){
            return mid;
        }
        else if(mid*mid < N){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
        // linear search
        float inc =0.1;
        for (int place =1; place<=P ; place++){
            while(ans*ans <=N){
                ans += inc;
            }
            ans =ans -inc;
            inc  = inc/10;
        }



    return ans;
}

int main(){

    int n, p;
    cin>> n >> p;
    cout<< squareroot(n ,p)<< endl;



}