#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// generate all  subs, generate their has values, use multimap with their hash values as the key and use permutationto calc anagrams
vector<int > getHashValue( string s , int i , int j){
    vector <int> freq(26,0);
    
    for(int k = i; k<=j ; k++){
        char ch = s[k];
        freq[ch - 'a']++;
    }
    return freq;

}

int anagramSubstrings(string s){
    // creating subs
    map<vector <int> , int> m;
   int n = s.length();    
    for(int i = 0 ; i<n; i++){
        for(int j = i ; j<n ; j++){
            vector <int> h = getHashValue(s,i,j);
            m[h]++;
        }
    }
    int ans = 0;
    for(auto x: m){
        int freq = x.second;
        ans += (freq)*(freq - 1)/2;
    }
    return ans;
}
int main(){
    string s;
    cin >> s;
    cout  << anagramSubstrings(s) << endl;
}
