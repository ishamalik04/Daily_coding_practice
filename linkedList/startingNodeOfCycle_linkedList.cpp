class Solution {
public:
    ListNode* detectStartNode(ListNode*head)
    {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode*intersection=detectStartNode(head);
        if(intersection==NULL)
        {
            return NULL;
        }
        ListNode*slow=head;
        while(slow!=intersection)
        {
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
    }
};
