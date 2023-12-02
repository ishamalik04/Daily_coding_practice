class Solution {
public:
    ListNode* getMid(ListNode*head)
    {
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode*head)
    {
        ListNode*prev=NULL;
        ListNode*current=head;
        ListNode*next=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        {
            return true;
        }
        ListNode*middle=getMid(head);
        ListNode*temp=head;
        ListNode*temp2=middle->next;
        middle->next=reverse(temp2);
        temp2=middle->next;
        while(temp2!=NULL)
        {
           if(temp->val !=temp2->val)
           {
               return false;
           }
           temp=temp->next;
           temp2=temp2->next;
        }
        temp=middle->next;
        middle->next=reverse(temp);
        return true;
    }
};
