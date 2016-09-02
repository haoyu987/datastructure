// recursive
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* node=head->next;
        ListNode* newhead=reverseList(node);
        head->next=NULL;
        node->next=head;
        return newhead;
    }
    
// iterative
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *pre=NULL,*cur=head,*tmp;
        while(cur){
            tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
