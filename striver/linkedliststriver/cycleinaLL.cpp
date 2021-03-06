//https://leetcode.com/problems/linked-list-cycle/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL)return false;
        ListNode * fast= head;
        ListNode * slow = head;
        
        while(fast->next != NULL and fast->next ->next != NULL){
            fast = fast->next ->next;
            slow = slow->next;
            if(fast == slow)return true;
            
            
        }
        return false;
        
        
    }
};