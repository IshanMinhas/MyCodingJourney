#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

string find_window(string s , string p){
    int FP[256] = {0};
    int FS[256] ={0};
    for(int  i = 0 ; i<p.length(); i++){


        FP[p[i]]++;
    }
    int cnt =0;
    int start =0;
    int  start_idx = -1;
    int min_so_far = INT_MAX;
    int window_size ;

    for(int i =0 ; i<s.length(); i++){
        char ch =s[i];
        FS[ch]++;
        
        if(FP[ch]!=0 and FS[ch]<= FP[ch]){
            cnt +=1;
        }
        if(cnt==p.length()){
            while(FP[s[start]] == 0 or FS[s[start]]> FP[s[start]]){
                FS[s[start]]--;
                start++ ;

            }
            window_size  = i-start+1;
            if(window_size< min_so_far){
                min_so_far =window_size ;
                start_idx = start;

            }
        }


    }
    if(start_idx == -1){
        return " no window found";

    }
    return s.substr( start_idx, min_so_far);
    

}

int main(){
    string p , s;
    cin>> s>> p;
    cout<< find_window(s,p)<< endl;






}