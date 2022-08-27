class Solution {
public:
    Node* copyRandomList(Node* head) {
   

    map<Node *,Node *>mp;
	int i=0;
	Node *ptr = head;
	while(ptr){
		mp[ptr] = new Node(ptr->val);
		ptr = ptr->next;
	}
	ptr = head;
	while(ptr){
		mp[ptr]->next = mp[ptr->next];
		mp[ptr]->random = mp[ptr->random];
		ptr = ptr->next;
	}
	return mp[head];
}
    
};