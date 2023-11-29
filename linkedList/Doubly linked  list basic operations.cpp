//Doubly linked  list basic operations
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertAtBegin(Node* &head,int data)
{
    Node*temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtEnd(Node* &head,int data)
{
    Node*node1=new Node(data);
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node1;
    node1->prev=temp;
}
void insertAtPos(Node*&head,int data,int n)
{
    if(n==1)
    {
        insertAtBegin(head,data);

    }
    else
    {
    Node*node1=new Node(data);
    Node*temp=head;
    int cnt=1;
    while(cnt<n-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtEnd(head,data);
    }
    else
    {
    node1->next=temp->next;
    temp->next->prev=node1;
    temp->next=node1;
    node1->prev=temp;
    }
    }
}
void print(Node* &head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleteNode(Node*&head,int pos)
{
    if(pos==1)
    {
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->next->prev=prev;
        prev->next=curr->next;
        curr->next=NULL;
        curr->prev=NULL;

        delete curr;
    }
}
bool search(Node*&head,int data)
{
    Node*temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==data)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main()
{
    int n,pos,s;
    Node*node1=new Node(10);
    Node*head=node1;
    print(head);
    insertAtBegin(head,20);
    print(head);
    insertAtBegin(head,30);
    print(head);
    insertAtEnd(head,90);
    print(head);
    insertAtEnd(head,100);
    print(head);
    cout<<"enter position you want to insert element"<<endl;
    cin>>n;
    insertAtPos(head,33,n);
    print(head);
    cout<<"enter position you want to delete the element at"<<endl;
    cin>>pos;
    deleteNode(head,pos);
    print(head);
    cout<<"enter element you want to search"<<endl;
    cin>>s;
    if(search(head,s))
    {
        cout<<"Yes,element found";
    }
    else
    {
        cout<<"No,element not found";
    }
}


