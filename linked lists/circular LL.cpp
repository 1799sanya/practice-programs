#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void insert(node*&head,int data)
{
    node*n=new node(data);
    node*temp=head;
    n->next=head;
    if(temp!=NULL)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    else{
        //self loop
        n->next=n;
    }
    head=n;
}

node* getNode(node*head,int data)
{
    node*temp=head;
    //check for all nodes except last node
    while(temp->next!=head)
    {
        if(temp->data==data)
        {
            return temp;
        }
        temp=temp->next;
    }
    //out of loop, check for last node
    if(temp->data==data)
    {
        return temp;
    }
    return NULL; //node not present
}

void deleteNode(node*&head,int data)
{
    node* del=getNode(head,data); //node to be deleted
    if(del==NULL)
    {
        //node not present
        return;
    }
    //otherwise
    if(head==del)
    {
        head=head->next;
    }
    node*temp=head;
    //stop one step behind the node to be deleted
    while(temp->next!=del)
    {
        temp=temp->next;
    }
    temp->next=del->next;
    delete del;
}

void print(node*head)
{
    node*temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    return;
}

int main()
{
    node*head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    print(head);
    deleteNode(head,3);
    print(head);
    deleteNode(head,1);
    print(head);
    return 0;
}
