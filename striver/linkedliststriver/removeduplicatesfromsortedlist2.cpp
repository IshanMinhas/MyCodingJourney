/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next== NULL)return head;
        ListNode * d= new ListNode(-100);
        ListNode * temp = d;
        ListNode * pt =head;
        temp->next = head;
        ListNode* jasoos = d ;
        while(pt and pt->next){
            if(jasoos->val == pt->val){
                temp->next = pt->next;
                pt = temp->next;
            }
            else if(pt->val == pt->next->val){
                jasoos = pt;
                temp->next  = pt->next->next;
                pt= temp->next;
            }
            else{
                temp = pt;
                pt = pt->next;
            }
        }
        
        if(pt and jasoos->val == pt->val){
            temp->next = pt->next;
        }
        
        
        return d->next;
    }
};