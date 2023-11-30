class Solution
{
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
    void removeLoop(ListNode*head)
    {
        if(head==NULL || head->next->next==NULL)
        {
            return;
        }
        ListNode*startNode=detectStartNode(head);
        if(startNode==NULL)
        {
            return;
        }
        ListNode*temp=startNode;
        while(temp->next!=startNode)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
};
