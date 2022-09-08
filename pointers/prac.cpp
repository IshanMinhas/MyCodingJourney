#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    //  int arr[5] = {1,2,3,4,6};
    //  char ch[6] = "abcde";
    //  char * ch2 = &ch[0];
    //  cout << " " << ch <<" " << " " << &ch[0] << &ch <<  endl; // ch - >puri string , &ch[0] -> puri string , &ch -> address of ch[0]
    //  // ch2 -> puri string ,*ch2 -> a , &ch2- >  addrese of ch2 block

    //  const char * ch1 = new char[10]; // if printed here then it prints till it finds null char at that
    //  // mem location if it doesnt find numm char then it prints till 10 chars
    //  // use 
    //  ch1 = "aasasa"; // constant string is defined to non constant pointer which is wrong cuz we might reach read only mem or
    //  // mem that shouldnt be accessed by us thru pointer for constant value of string
    
    
    
    
    
    
    
    // // use const for constant string 
    
    
    
    // //  char * ch3 = "abacde"; // Don't do this //warning cuz we might reach read only memory 
   
    // cout << ch1  <<" " << *ch2 << ch2 <<&ch2 << endl;


















    int arr[10] = {10 , 20 , 6};
    cout << arr <<endl;
    cout << &arr <<endl; // &arr == &arr[0]
    cout << sizeof(arr) <<endl;  //size of array total 4 * 10
    cout << *arr<<endl; // value deref at arrblock
    cout << *arr + 1 <<endl; // value at 0 index + 1
    cout <<*(arr +1 ) <<endl; // arr == address of 0 index + 1(add 4/8bytes) and get value at that address using deref
    cout << arr[2] << " " << 2[arr] <<endl;  // formula is *(arr + i) == arr[i] == i[arr]
    int * ptr = &arr[0];
    cout << ptr << " " <<  arr << " " << &arr[0]  << " " << &arr << endl; // all are same and show add of arr[0]
    // BEWARE........  jahan pe bhi address stored hota hai wo 8 bytes ka hota hai conventionally but mera pc 4 byte dekhta hai 
    cout << sizeof(arr[0])  << " " <<sizeof(ptr ) << " " << sizeof(arr) <<endl; // should be  4 8 40
    int * ptr1 = &arr[0];
    int ** ptr2 = &ptr1;
    cout << &ptr2 << " " <<ptr2 << " " <<  &ptr1 << " " << ptr1 << " "<< *ptr1 <<endl;


}