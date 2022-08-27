 Node*curr=head;
       while(curr->next!=NULL){
           curr=curr->next;
       }
       while(k--){
       Node*temp=head;
       head=temp->next;
         temp->next=NULL;
        curr->next=temp;
        curr=curr->next;
        
         
       }
       return head;