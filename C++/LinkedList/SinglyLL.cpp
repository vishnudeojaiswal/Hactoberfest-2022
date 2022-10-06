#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};
void InserAtHead( Node* &head, int d)
{
    //new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node* &tail,int  d)
{
    //new node
    Node* temp = new Node(d);
    tail->next =  temp;
    tail = temp;

}
void inserAtPos(Node* &tail,Node * &head,int pos, int d)
{
    Node* temp = head;
    int c = 1;
    if(pos==1)
    {
        InserAtHead(head,d);
        return;
    }
    while (c<pos-1)
    {
        temp = temp->next;
        c++;
    }
    //creating node for d
    Node* nodenew = new Node(d);
    nodenew->next = temp->next;
    temp->next = nodenew;
    if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
        return;
    }

}
void deleteNode(int position, Node* &head,Node* &tail)
{
     if(position == 1)
     {
         Node* temp = head;
         head = head->next;
         delete(temp);
     }
     else
     {
        Node* curr = head;
        Node* pre = NULL;
        int c =1;
        while (c<position)
        {
            pre = curr;
            curr = curr->next;
            c++;
        }
        pre->next = curr->next;
        if(curr->next==NULL)
        {
            tail = pre;
        }
        delete(curr);

     }
}
void print(Node* &head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtTail(tail,12);
    print(head);
    InsertAtTail(tail,15);
    print(head);
    inserAtPos(tail,head,4,22);
    print(head);
    // deleteNode(1,head,tail);
    // print(head);
    deleteNode(3,head,tail);
    print(head);
    return 0;
}