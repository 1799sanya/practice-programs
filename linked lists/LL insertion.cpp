#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    //constructor
    node(int d)
    {
        data=d;
        next=NULL;
    }

};

int length(node*head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len+=1;
    }
    return len;
}

void insertAtHead(node*&head,int data)
{
    node*n=new node(data);
    n->next=head;
    head=n;
}

void insertAtTail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}

void insertInMiddle(node*&head,int data,int p)
{
    if(head==NULL || p==0)
    {
        insertAtHead(head,data);
    }
    else if(p>length(head))
    {
        insertAtTail(head,data);
    }
    else{
        //insert in middle
        //take p-1 jumps
        int jump=1;
        node*temp=head;
        while(jump<=p-1)
        {
            temp=temp->next;
            jump+=1;
        }
        node*n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}

void print(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAtHead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    node*temp=head;
    head=head->next;
    delete temp;
    return;
}

void deleteAtTail(node*&head)
{
    node*prev=NULL;
    node*temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    //now temp points to last node and previous to second last node
    delete temp;
    prev->next=NULL;
    return;
}

void deleteInTheMiddle(node*&head,int p)
{
    if(p==0)
    {
        deleteAtHead(head);
    }
    else if(p>length(head))
    {
        deleteAtTail(head);
    }
    else{
        node*prev=NULL;
        node*temp=head;
        int jump=1;
        while(jump<=p-1)
        {
            prev=temp;
            temp=temp->next;
            jump+=1;
        }
        //now temp points to the node to be deleted
        prev->next=temp->next;
        delete temp;
        return;
    }
    //return;
}

node* midPoint(node*head)
{
    if(head==NULL||head->next==NULL)
    {
        //0 or 1 node
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

//find kth node from the last of LL
node* kFromLast(node*head,int k)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* fast=head;
    node* slow=head;
    int jump=1;
    while(jump<=k)
    {
        fast=fast->next;
        jump+=1;
    }
    //node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow->next;
}

bool searchRecursive(node*head,int key)
{
    //base
    if(head==NULL)
    {
        return false;
    }
    //rec
    if(head->data==key)
    {
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}

bool searchIterative(node*head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}
//inputting list from user
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

void reverseLL(node*&head)
{
    node*C=head;
    node*P=NULL;
    node*N;
    while(C!=NULL)
    {
        //save the next node
        N=C->next;
        //make current node point to previous
        C->next=P;
        //update previous and current
        P=C;
        C=N;
    }
    head=P;
}
int main()
{
    node*head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,6);
    insertAtTail(head,7);
    //insertAtTail(head,8);
    //insertInMiddle(head,2,3);
    //print(head);
    //deleteAtHead(head);
    //deleteAtTail(head);
    //deleteInTheMiddle(head,3);
    print(head);
    /*if(searchRecursive(head,5))
    {
        cout<<"element present"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    if(searchIterative(head,14))
    {
        cout<<"element present"<<endl;
    }
    else{
        cout<<"element not present"<<endl;
    }*/
   // buildList(head);
    //print(head);
    //reverseLL(head);
    //print(head);
    node*m=midPoint(head);
    cout<<m->data<<endl;
    int k;
    cin>>k;
    node*ans=kFromLast(head,k);
    cout<<ans->data<<endl;
    return 0;
}
