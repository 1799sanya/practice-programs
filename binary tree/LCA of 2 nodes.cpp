#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node*left;
	node*right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* buildTree(string s)
{
	if(s=="true")
	{
		int d;
		cin>>d;
		node*root=new node(d);
		string l;
		cin>>l;
		if(l=="true")
		{
			root->left=buildTree(l);
		}
		string r;
		cin>>r;
		if(r=="true")
		{
			root->right=buildTree(r);
		}
		return root;
	}
	return NULL;
}

node* lca(node*root,int a,int b)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==a || root->data==b)
	{
		return root;
	}
	//search in the ls and rs
	node* leftans=lca(root->left,a,b);
	node* rightans=lca(root->right,a,b);

	if(leftans!=NULL && rightans!=NULL)
	{
		return root;
	}
	if(leftans!=NULL)
	{
		return leftans;
	}
	return rightans;
}

int main() {
	node*root=buildTree("true");
	int a,b;
	cin>>a>>b;
	cout<<lca(root,a,b)->data;

	return 0;
}
