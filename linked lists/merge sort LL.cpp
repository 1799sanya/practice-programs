#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

node* midPoint(node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* merge(node*a,node*b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    node*c;
    if(a->data<b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

node* mergeSort(node*head)
{
    //base
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //rec
    //1. divide
    node* mid=midPoint(head);
    node* a=head;
    node* b=mid->next;
    mid->next=NULL;

    //2. rec sort the 2 parts
    a=mergeSort(a);
    b=mergeSort(b);

    //3. merge them
    node* c=merge(a,b);
    return c;
}

void insertAtTail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}

void buildList(node*&head)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertAtTail(head,data);
        cin>>data;
    }
}

void print(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    node*head=NULL;
    buildList(head);
    head=mergeSort(head);
    print(head);
    return 0;
}
