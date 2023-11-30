class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*current=head;
        while(current->next!=NULL)
        {
            if((current->val==current->next->val) && (current->next!=NULL))
            {
                ListNode*next=current->next->next;
                ListNode*nodeDelete=current->next;
                delete(nodeDelete);
                current->next=next;
            }
            else
            {
                current=current->next;
            }
        }
        return head;
    }
};
