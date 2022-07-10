#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(string x ,string y){
    return x+y < y+x;



}
int main(){
    string arr[] = { "a" , "ab" , "aba"};
    int n =3;
    sort(arr ,arr+n , compare);
     for(auto s: arr){
         cout<<s;
     }
    
}