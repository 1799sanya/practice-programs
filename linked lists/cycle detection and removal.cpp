/*void removeLoop(Node* &head,Node*fast){
    Node* slow = head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next = NULL;
    //cout<<fast<<" is the last node.";
}

bool floydCycleRemoval(Node *head)
{
    //Code here
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            removeLoop(head,fast);
            return true;
        }
    }
    return false;
}*/

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

void insertAtTail(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new node(data);
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

void removeLoop(node*&head,node*fast)
{
	node*slow=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	fast->next=NULL;
}
bool detectCycle(node*head)
{
	node*slow=head;
	node*fast=head;
	while(fast!=NULL || fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
		{
			removeLoop(head,fast);
			return true;
		}
	}
	return false;
}

void print(node*head)
{
	node*temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<" ";
	}
}

int main() {
	node*head=NULL;
	buildList(head);
	detectCycle(head);
	print(head);
	return 0;
}
