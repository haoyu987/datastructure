/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *fast=head,*slow=head,*tmp,*nextnode;
        stack<ListNode*> nodestack;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next) slow = slow->next;
        while(slow){
            nodestack.push(slow);
            slow = slow->next;
        }
        nextnode = head;
        while(nodestack.size()>1){
            tmp = nextnode->next;
            nextnode->next = nodestack.top();
            nodestack.pop();
            nextnode->next->next=tmp;
            nextnode = tmp;
        }
        nodestack.top()->next=NULL;
    }
};

class Solution2 {
public:
// O(N) time, O(1) space in total
void reorderList(ListNode *head) {
    if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }
    
    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
};

class Solution3{
public:
    void reorderList(ListNode* head) {
        
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Find the mid point
        while (fast !=  NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Start weaving
        weave(head, slow);
    }

private:
    ListNode* weave(ListNode* forward, ListNode* slow)
    {
        // Weaving starts when you hit end of the list
        if (slow->next == NULL)
        {
            return forward;
        }
        ListNode* tmp = weave(forward, slow->next);
        ListNode* tmp1 = slow->next;
        slow->next = tmp1->next;
        tmp1->next = tmp->next;
        tmp->next = tmp1;
        
        return tmp1->next;
    }
};
