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

node* kFromLast(node*head,int k)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node*fast=head;
	int jump=1;
	while(jump<=k)
	{
		fast=fast->next;
		jump+=1;
	}
	node*slow=head;
	while(fast!=NULL)
	{
		fast=fast->next;
		slow=slow->next;

	}
	return slow;
}
int main() {
	node* head=NULL;
	buildList(head);
	int k;
	cin>>k;
	node*a=kFromLast(head,k);
	cout<<a->data<<endl;
	return 0;
}
