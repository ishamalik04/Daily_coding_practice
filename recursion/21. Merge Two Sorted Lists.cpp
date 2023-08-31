21. Merge Two Sorted Lists
Easy
19.8K
1.8K
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         struct ListNode *temp = new ListNode(0),*head = new ListNode(0);
        int flag=0;
        if(l1==NULL && l2==NULL)
           return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        else
        while(l1!=NULL && l2!=NULL)
        {
          if(l1->val < l2->val)
          {
            if(flag==0)
            {
               head=l1;
               temp=head;
            }
            else
            {
               temp->next=l1;
               temp=temp->next;
            }
            l1=l1->next;
           }
           else
           {
               if(flag==0)
               {
               head=l2;
               temp=head;
            }
                else
                   {
                       temp->next=l2;
                       temp=temp->next;
                    }
            l2=l2->next;
           }
           flag=1;
    }
    while(l1!=NULL)
    {
        temp->next=l1;
        temp=temp->next;
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        temp->next=l2;
        temp=temp->next;
        l2=l2->next;
    }

           return head;
    }
};
