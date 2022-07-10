#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Bracketsgeneration( string output , int n ,int open , int close , int i){
    //base
    if(i == 2*n){
        cout << output << endl;
        return;

    }
    // open
    if(open< n){
        Bracketsgeneration(output +'(' , n , open+1 , close ,i+1);
    }
    // close
    if(close< open){
        Bracketsgeneration(output + ')' , n , open , close+1 , i+1);
    }



}

int main(){
    string output;
    int n;
    cin>> n;
    Bracketsgeneration( output , n , 0, 0, 0);

}
