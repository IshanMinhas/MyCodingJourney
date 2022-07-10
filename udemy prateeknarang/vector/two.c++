#include<iostream>
#include<vector>
using namespace std;
int main(){

    // vector<int> arr = { 1 , 2, 3 , 4 , 5};
    
    
    // arr.push_back(16);
    // for(int i =0 ; i< arr.size() ; i++){
    //     cout<< arr[i]<<endl;


    vector < vector<int>> arr = { {1,2} , { 2,3,4} , { 4,5,6,7}};
      
       for( int i =0 ; i<arr.size() ; i++){
           for( int x : arr[i]){
               cout<< x<< ",";
           }
        cout<< endl;
            
    } 

    }     
  