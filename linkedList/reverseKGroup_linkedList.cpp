class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == NULL) return head;
            cursor = cursor->next;
        }
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*next=NULL;
        ListNode*prev=NULL;
        ListNode*current=head;
        int cnt=0;
        while(current!=NULL && cnt<k)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            cnt++;
        }
        if(next!=NULL)
        {
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
};
