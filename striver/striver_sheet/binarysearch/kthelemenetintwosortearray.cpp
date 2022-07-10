#include<iostream>
using namespace std;

int kthelement(int array1[],int array2[],int m,int n,int k) {
    int p1=0,p2=0,counter=0,answer=0;
    
    while(p1<m && p2<n) {
        if(counter == k) break;
        else if(array1[p1]<array2[p2]) {
            answer = array1[p1];
            ++p1;
        }
        else {
            answer = array2[p2];
            ++p2;
        }
        ++counter;
    }
    if(counter != k) {
        if(p1 != m-1) 
            answer = array1[k-counter];
        else 
            answer = array2[k-counter];
    }
    return answer;
}

int main() {
    int array1[] = {2,3,6,7,9};
    int array2[] = {1,4,8,10};
    int m = sizeof(array1)/sizeof(array1[0]);
    int n = sizeof(array2)/sizeof(array2[0]);
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "
    <<kthelement(array1,array2,m,n,k);
    return 0;
}