203. Remove Linked List Elements
Easy
7.7K
217
Companies
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.



Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []



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
    ListNode* removeElements(ListNode* head, int val) {
      if(head==NULL)
      {
          return NULL;
      }
      head->next=removeElements(head->next,val);
      if(head->val==val)
      {
          return head->next;
      }
      else
      {
          return head;
      }
    }
};
/*
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }

        while(head!=NULL && head->val==val)
        {
            head = head->next;
        }
        ListNode* temp = head;

        while(temp!=NULL)
        {
            if(temp->next!=NULL && temp->next->val==val)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};
*/
