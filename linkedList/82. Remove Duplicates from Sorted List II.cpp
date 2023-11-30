class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*current=head;
        ListNode*prev=head;
        ListNode*t=NULL;
        while(current!=NULL)
        {
            if((current->next!=NULL)&&(current->val==current->next->val))
            {
                t=current;
                while(current!=NULL && current->val==t->val)
                {
                    current=current->next;
                }
                if(t!=head)
                {
                    prev->next=current;
                }
                else
                {
                    head=current;
                    return deleteDuplicates(head);
                }
            }
            else
            {
                prev=current;
                current=current->next;
            }
        }
        return head;
    }
};
