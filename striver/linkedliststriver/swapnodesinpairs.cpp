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
    ListNode* swapPairs(ListNode* head) {
        ListNode * d = new ListNode();
        ListNode * temp = d;
        temp->next = head;
        while(temp->next and temp->next->next){
            ListNode *cur = temp->next;
            temp->next = temp->next->next;
            cur->next = temp->next->next;
            temp->next->next = cur;
            temp = cur;
        }
        return d->next;
    }
};