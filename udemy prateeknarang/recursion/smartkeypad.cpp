#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string keypad [] = {"" , "" , "ABC" , "DEF", "GHI" , "JKL" ,"MNO" ,"PQR" , "STUW" ,"XYZ"    };
void KeypadLetter(string input , string output , int i =0){
    //base
    if(input[i] == '\0'){
        cout << output << endl;
        return;
    }
    //rec
    int current_digit = input[i] - '0';
    if(current_digit == 0 or current_digit == 1){
        KeypadLetter(input, output ,i+1);
    }

    for( int k= 0 ; k< keypad[current_digit].size() ; k++ ){
        KeypadLetter(input , output + keypad[current_digit][k], i+1 );

    }
    return;
}


int main(){
    string input;
    cin >>input ;
    string output;
    KeypadLetter(input ,output);
}