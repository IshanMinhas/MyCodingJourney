#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node * head,int k){
    //Complete this function to return kth last element
    node * fast = head;
    node * slow = head;
    
    int cnt = 0;
    while(cnt < k){
        fast = fast->next;
        cnt++;
    }
    
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow->data;
}

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

void PrintLinkedList( node * head){
    // as we are not changnig the head anymore so we are passing by value , but we can also do pass by ref , doesnt matter
    while(head!= NULL){
        cout<< head->data<< "-->";
        head =head->next;


    }
    cout<<endl;

}

int main(){


    node *a =NULL;
    InsertatHead(a , 5);
    InsertatHead(a , 3);InsertatHead(a , 2);InsertatHead(a , 1);
    PrintLinkedList(a);
     kthLastElement(a,2);








}