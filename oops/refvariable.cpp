#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void update(int &n ){
    cout << "before" << n <<endl; 
    n++;
    cout <<"after " << n <<endl;

}
// return by ref is bad... AVOID ....  int & fnc(int n)

int main(){

    int n = 5;
    cout  << "before" << n ;
    update(n);
    cout << "after  " <<n  << endl;




    
    // int i= 0;
    // //just name/ alias / nickname add kar rahe hai
    // int &j  = i;
    // cout << &i << " "<< &j <<endl;
    // i++;
    // cout << i << endl;
    // j++;
    // cout << i << endl;
    

}