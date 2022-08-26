#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
 class heap{
    public : 
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0 ;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index]= val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent ]< arr[index]){
                swap(arr[index]  , arr[parent]);
                index= parent;
            }else return;
        }
    }


    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << endl;
        }

    }
    void print1(){
        cout << arr[size +1 ]<< endl;
    }

    void deletefromheap(){
        //swap the top element of heap with the last element of the heap 
        // can use swap or just set the value of the arr[1] as arr[size] swap(arr[1] , arr[size]);
        arr[1] = arr[size];
        
        size--;

    // putting the swapped small value(in case of max heap) at its correct pos
        int i = 1 ;
        while(i < size){
            // checking for left child and right child
            int leftchild = i *2;
            int rightchild = 2*1 +1 ;
            if(leftchild <= size and arr[leftchild] > arr[i]){
                swap(arr[leftchild], arr[i]);
                i = leftchild;
            }
            if(rightchild <= size and arr[rightchild] > arr[i]){
                swap(arr[rightchild], arr[i]);
                i = rightchild;
            }
            else{
                return;
            }
        }
    }


 };
void heapify(int arr[] , int n , int i){
    int largset = i;
    int leftchild  = 2* i;
    int rightchild = 2*i +1 ;
    if(leftchild <= n and arr[largset] < arr[leftchild]){
        largset = leftchild;
    }
    if(rightchild <=  n and arr[largset] < arr[rightchild]){
        largset = rightchild;
    }
    if(largset != i){
        swap(arr[largset] , arr[i]);
        heapify(arr, n , largset);
    }
}

void heapSort(int arr[] , int n){
    int size = n ; 
    while(size > 1 ){
        swap(arr[size] , arr[1]);
        size--;
        heapify(arr,size , 1);
    }
}

int main(){
   
//    // insert , delete
//     heap h1;
//     h1.insert(21);
//     h1.insert(16);
//     h1.insert(56);
//     h1.insert(46);
//     h1.insert(5);
//     h1.print();
//     h1.deletefromheap();
//     h1.print();
//     h1.print1();






    int arr[6] = {-1 , 3, 100 ,1 ,5 , 26 };
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, 5, i);
    }
    for(int i= 1 ;i<= n; i++){
        cout << arr[i] << " " ;
    }cout << endl;

    return 0;
}