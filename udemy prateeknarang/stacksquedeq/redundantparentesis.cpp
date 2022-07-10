#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool redundantParenthesis(string str){
    stack<char> s;
    for(auto ch : str){
        if(ch != ')'){
            s.push(ch);
        }
        else{
            bool operatorFound = false;
            while(!s.empty() and s.top() != ')'){
                char top = s.top();
                if(top == '+' or top == '-' or top == '/' or top == '*'){
                    operatorFound = true;
                }
                s.pop();
            }
            s.pop(); // for '('
            if(operatorFound == false){
            return true;
            }
        }
        
    }
        return false;
}

int main(){
    string str;
    if(redundantParenthesis(str)){
        cout<< "redundant par"<<endl;
    }
    else{
        cout<< "not re"<< endl;

    }
}