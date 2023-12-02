class Solution
{
    void insertAtTail(Node*&tail,Node*current)
    {
        tail->next=current;
        tail=current;
    }
    public:

    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {

      Node*oneHead=new Node(0);
      Node*twoHead=new Node(0);
      Node*zeroHead=new Node(0);
      Node*oneTail=oneHead;
      Node*zeroTail=zeroHead;
      Node*twoTail=twoHead;
      Node*current=head;
      while(current!=NULL)
      {
          int value=current->data;
          if(value==0)
          {
              insertAtTail(zeroTail,current);
          }
          else if(value==1)
          {
              insertAtTail(oneTail,current);
          }
          else if(value==2)
          {
              insertAtTail(twoTail,current);
          }
          current=current->next;
      }

    if(oneHead->next!=NULL)
    {
        zeroTail->next=oneHead->next;
    }
    else
    {
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
    }
};
