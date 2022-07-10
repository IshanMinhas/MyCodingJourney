#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;
// imp code
// istringstream ostringstream and multiple corner cases
string SimplifyPath(string path){
    istringstream iss(path);
    vector<string> tokens;
    string token;
    while(getline(iss , token , '/')){
        if(token == "." or token == ""){
            continue;
        }
        tokens.push_back(token);
        
    }
    // handle
    vector<string> stack ;
    if(path[0] == '/'){
        stack.push_back("");
    }
    for(string token: tokens){
        if(token == ".."){
            // 2 cases abs and rel
            if(stack.size() == 0 or stack[stack.size()-1] == ".."){
                stack.push_back("..");
            }
            else if(stack[stack.size()- 1] != ""){
                stack.pop_back();
            }
        }
        else{
            stack.push_back(token);
        }
    }
    if(stack.size() == 1 and stack[0] == ""){
        return "/";
    }
    ostringstream oss;
    int i =0;
    for(auto token : stack){
        if(i!= 0){
            oss<<  "/";

        }
        i++;
        oss<< token;
    }
    return oss.str();

    }
int main(){
    string path = "/../x/y/../z/././w/a///../../c/./";
    // output: /x/z/c
    cout<< SimplifyPath(path)<< endl;

}