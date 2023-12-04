class Solution {
public:
    void insertAtTail(Node*&head,Node*&tail,int data)
    {
        Node*newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        //step1. create a clone list
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node*temp=head;
        while(temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        //step2. cloneNodes add b/w orig list

        Node*origNode=head;
        Node*cloneNode=cloneHead;

        while(origNode!=NULL &&cloneNode!=NULL)
        {
            Node*next=origNode->next;
            origNode->next=cloneNode;
            origNode=next;
            next=cloneNode->next;
            cloneNode->next=origNode;
            cloneNode=next;
        }

        //step3. random pointer copy

        temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(temp->random!=NULL)
                {
                    temp->next->random=temp->random->next;
                }
            }
            temp=temp->next->next;
        }
        //step 4. revert changes done in step2.
        origNode=head;
        cloneNode=cloneHead;
        while(origNode!=NULL && cloneNode!=NULL)
        {
            origNode->next=cloneNode->next;
            origNode=origNode->next;
            if(origNode!=NULL)
            {
                cloneNode->next=origNode->next;
            }
            cloneNode=cloneNode->next;
        }
        return cloneHead;

    }
};
