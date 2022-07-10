#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
 public:
 int data;
 node * next;
    
 
 node(int data){
     this->data =data;
     next =NULL;
    // or another way is getter setter fncs
    /* node* getnext(){
        ..
    }
    int getdata(){
        return ;
    }
*/
 }};


// datatype is ready ... now we work on creating a LL 
// ---------------------------------------------------//
void InsertatHead( node * &head ,int data ){// if we dont pass it by ref(&head) then changes wont be reflected inside main
    if(head == NULL){
        head =new node(data);
        return;
    }    
    // otherwise
    node * n =new node(data);
    n->next =head;
    head =n;
}

// void InsertintheMiddle( node * &head , int data , int pos){

//     if(pos ==0){
//         InsertatHead(head ,data);
//     }
//     else{
//         node * temp= head ;
//         for(int jump= 1 ; jump<=pos-1 ;jump++){
//             temp = temp->next;
//         }
//         node *n =new node(data);
//         n->next = temp->next;
//         temp->next = n;




//     }

// }

// node * recReverse(node * head){
//     // here we written the head of reversed LL
//     //base case
//     if( head == NULL or head->next == NULL){
//         return head;
//     }
//     node *sHead = recReverse(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return sHead;

// }

// void IterReverse(node * &head){
// // Iterative fncs do not use stack memory, hence they are better than rec which take extra space in stack mem
// // space comp = o(1) ,  time =o(n)........... for rec space is o(n), time = o(n)
//     node * temp;
//     node * prev = NULL;
//     node * current = head;
//     while(current!=NULL){
//         temp = current->next;
//         current->next = prev;

//         // update the variables now
//         prev =current;
//         current = temp;
//     }

//     head = prev;
//     return;

// }
node * midPoint(node * head){

    node * slow =head ; 
    node *fast =head ->next;
    while(fast!= NULL and fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;// midtpt
    


}


node* merge(node *a ,node *b){
    //base c
    if(a == NULL){
        return b;
    }
    if(b== NULL){
        return a;
    }

    //rec case
    //we use a pointer c which will updtae on every rec call
    //space comp = o(a+b) ,time is also same

    node * c;
    if(a->data < b->data){
        c=a;
        c->next = merge(a->next , b);
    }
    else{
        c=b;
        c->next = merge(a , b->next);
    }
    return c;
}


node * mergeSort(node * head){
    //base c


    if(head == NULL or head->next == NULL){
        return head;
    }

    //rec c
    node * mid = midPoint(head);
    // break at the mid point
    node *a =head;
    node * b = mid->next;
    mid ->next = NULL;
    // rec sort
    a = mergeSort(a);
    b = mergeSort(b);

    // merge them
    return merge(a,b);
}





void PrintLinkedList( node * head){
    // as we are not changnig the head anymore so we are passing by value , but we can also do pass by ref , doesnt matter
    while(head!= NULL){
        cout<< head->data<< "-->";
        head =head->next;


    }
    cout<<endl;

}
// node * kReverse ( node * head , int k){
//     if(head == NULL){
//         return NULL;
//     }
//     node * temp;
//     node * prev = NULL;
//     node * current = head;
//     int cnt = 1;
//     while(current!=NULL and cnt<=k){
//         temp = current->next;
//         current->next = prev;

//         // update the variables now
//         prev =current;
//         current = temp;
//         cnt++;
//     }
//     if(temp!=NULL){
//         head->next = kReverse(temp, k);


//     }
//     return prev;

// }



int main(){
    node * a =NULL;
    InsertatHead(a,10);
    InsertatHead(a,7);
    InsertatHead(a,8);
    InsertatHead(a,100);
    InsertatHead(a,2);
    InsertatHead(a,1);
    InsertatHead(a,69);
    PrintLinkedList(a);
    a= mergeSort(a);
    PrintLinkedList(a);

//     node *a = NULL;
//    InsertatHead(a,10);
//    InsertatHead(a,8);InsertatHead(a,7);InsertatHead(a,1);

//    node*b =NULL;
//    InsertatHead(b,6);   InsertatHead(b, 3);InsertatHead(b,2);

//     node* head = merge(a,b);
//     PrintLinkedList(head);

    // node * head =NULL;
    // InsertatHead(head ,4);
    //  InsertatHead(head ,3); InsertatHead(head ,2); InsertatHead(head ,1); InsertatHead(head ,0);
    // //InsertintheMiddle(head ,100 ,3);
    // PrintLinkedList(head);
    // // head = recReverse(head);
    // // IterReverse(head);
    // head = kReverse(head,3);
    
    // PrintLinkedList(head);

}