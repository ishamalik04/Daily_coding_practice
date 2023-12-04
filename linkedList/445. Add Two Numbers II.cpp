class Solution {
public:
    ListNode* reverse(ListNode*head)
    {
        ListNode*prev=NULL,*next=NULL,*curr=head;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void insertAtTail(ListNode*&head,ListNode*&tail,int val)
    {
        ListNode*newNode=new ListNode(val);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode*head=NULL,*tail=NULL;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int val1=0,val2=0;
            if(l1)
            {
                val1=l1->val;
            }
            if(l2)
            {
                val2=l2->val;
            }
            int sum=val1+val2+carry;
            int digit=sum%10;
            insertAtTail(head,tail,digit);
            carry=sum/10;
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode*ans=add(l1,l2);
        ans=reverse(ans);
        return ans;
    }
};
