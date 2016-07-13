/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // Floyd Cycle algorithm
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode *fast=head,*slow=head;
        bool flag=false;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                flag = true;
                break;
            }
        }
        if(!flag) return NULL;
        slow=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
