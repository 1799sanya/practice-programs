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
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

istream& operator>>(istream&is,node*&head)
{
    buildList(head);
    return is;
}

ostream& operator<<(ostream&os,node*head)
{
    print(head);
    return os;
}

node* merge(node*a,node*b)
{
    //base
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    //take a head pointer
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

int main()
{
    node* head=NULL;
    node* head2=NULL;
    cin>>head>>head2;
    cout<<head<<head2;
    node* newHead=merge(head,head2);
    cout<<newHead<<endl;
    return 0;

}
