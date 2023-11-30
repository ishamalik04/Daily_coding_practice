class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head->next;
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        if(head->next->next==NULL)
        {
            return head->next;
        }
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
};
