class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)
        {
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*current=dummy,*next=dummy,*prev=dummy;
        int count=0;
        while(current->next!=NULL)
        {
            current=current->next;
            count++;
        }
        while(count>=k)
        {
            current=prev->next;
            next=current->next;
            for(int i=1;i<k;i++)
            {
                current->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=current->next;
            }
            prev=current;
            count-=k;
        }
        return dummy->next;
    }
};
