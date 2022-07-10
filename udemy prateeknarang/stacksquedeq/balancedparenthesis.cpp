#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;
bool balancedParenthesis(string input){
    stack<char> s;
    for(auto ch :input){
        switch(ch){
            case '(':s.push(ch);
            break; 
            case '[':s.push(ch);
            break; 
            case '{': s.push(ch);
                  break;  
            case ')': if(!s.empty() and s.top() == '('){
                s.pop();
            }
            else{
                return false;
            }
            break;
            case ']': if(!s.empty() and s.top() == '['){
                s.pop();
            }
            else{
                return false;
            }
            break;
            case '}': if(!s.empty() and s.top() == '{'){
                s.pop();
            }
            else{
                return false;
            }break;
            default: continue;

        }

    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string input = "((a+b) + [d])";
    if(balancedParenthesis(input)){
        cout<< "balanced" <<endl;

    }
    else{
        cout<< "not B"<< endl;
    }
}