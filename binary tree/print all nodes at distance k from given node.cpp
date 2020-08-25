#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> v;

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

node* createTreeFromTrav(int in[],int pre[],int s,int e)
{
	static int i=0;
	if(s>e)
	{
		return NULL;
	}
	//rec
	node*root=new node(pre[i]);
	int index=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	i++;
	root->left=createTreeFromTrav(in,pre,s,index-1);
	root->right=createTreeFromTrav(in,pre,index+1,e);
	return root;
}

node* find(node*root,int t)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==t)
	{
		return root;
	}
	node*found=find(root->left,t);
	if(found!=NULL)
	{
		return found;
	}
	return find(root->right,t);
}

void printAtLevelK(node*root,int k,vector<int> &v)
{
	if(root==NULL)
	{
		return;
	}
	if(k==0)
	{
		//cout<<root->data<<" ";
		v.push_back(root->data);
		return;
	}
	printAtLevelK(root->left,k-1,v);
	printAtLevelK(root->right,k-1,v);
	return;
}

int printAtDistanceK(node*root,node*target,int k)
{
	//base
	if(root==NULL)
	{
		return -1;
	}
	//reach the target node
	if(root==target)
	{
		printAtLevelK(target,k,v);
		return 0;
	}
	//next step-ancestor
	int DL=printAtDistanceK(root->left,target,k);
	if(DL!=-1)
	{
		if(DL+1==k)
		{
			//cout<<root->data<<" ";
			v.push_back(root->data);
		}
		else
		{
			printAtLevelK(root->right,k-2-DL,v);
		}
		return 1+DL;
	}
	int DR=printAtDistanceK(root->right,target,k);
	if(DR!=-1)
	{
		if(DR+1==k)
		{
			//cout<<root->data<<" ";
			v.push_back(root->data);
		}
		else{
			printAtLevelK(root->left,k-2-DR,v);
		}
		return 1+DR;
	}
	return -1;
}

int main() {
	int n;
	cin>>n;
	int pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	int in[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node*root=createTreeFromTrav(in,pre,0,n-1);
	int t;
	cin>>t;
	while(t--)
	{
		int t,k;
		cin>>t>>k;
		node*target=find(root,t);
		printAtDistanceK(root,target,k);
		sort(v.begin(),v.end());
		if(v.size()==0)
		{
			cout<<"0";
		}
		else{
			for(int i=0;i<v.size();i++)
			{
				cout<<v[i]<<" ";
			}
		}

		cout<<endl;
		v.clear();
	}
	return 0;
}
