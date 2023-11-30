class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*prev=NULL;
        ListNode*forward=NULL;
        ListNode*current=head;
        while(current!=NULL)
        {
            forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
    }
};
