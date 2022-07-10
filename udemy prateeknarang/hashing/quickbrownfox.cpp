#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;


int minBarsHelper(string s , string words[], int idx , unordered_set<string> &m){
    // basec 
    if(s[idx] == '\0'){
        return 0;
    }
    // rec c
    int ans = INT_MAX;
    string current_string = "";
    for(int j = idx; s[j] !='\0' ; j++){
        current_string += s[j];
        if(m.find(current_string)!= m.end()){
            int remaining_ans = minBarsHelper(s , words , j+1 , m);
            if(remaining_ans!= -1){
                ans = min(ans, 1+ remaining_ans);
            }

        }
    }
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}
int min_bars(){
    string s="thequickbrownfoxj umpsove rthehighbridge";
string words [] = {"the", "fox", "thequickb rown fox", "j umps", "lazy", "lazyfox",
"highbridge", "the", "over", "bridge", "high", "tall",
"quick", "brown" }; 
    unordered_set< string > m;
    for(string w : words){
        m.insert(w);
    }
    int output = minBarsHelper(s , words , 0 , m);
    return output -1 ;
}
int main(){
    cout << min_bars()<< endl;
}
