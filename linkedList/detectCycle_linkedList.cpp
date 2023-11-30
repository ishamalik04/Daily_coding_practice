 class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
 };
/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return false;
        }
        map<ListNode*,bool>visited;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(visited[temp]==true)
            {
                return true;
            }
            visited[temp]=true;
            temp=temp->next;
        }
        return false;
    }
};*/
