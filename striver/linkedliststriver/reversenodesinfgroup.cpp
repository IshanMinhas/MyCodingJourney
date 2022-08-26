// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or k == 1 )return head;
        ListNode * dum = new ListNode(); dum ->next = head; ListNode * list = dum;
        ListNode * pre = dum; 
        ListNode * cur = dum ; 
        ListNode* nex = dum ; 
        int count = 0;
        while(cur ->next != NULL){
            cur = cur ->next ; 
            count ++ ;
            
        }
        
        while(count >= k ){
            cur = pre->next ;
            nex = cur ->next;
            for(int i =  0; i< k- 1; i++){
                cur ->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            
            
            }
            pre = cur;
            count -= k ;
            
            
            
        
        
        
        
        
        
        
        
        }
        
        return dum->next;
        
    }
};