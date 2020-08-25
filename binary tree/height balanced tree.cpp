#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        d=data;
        left=NULL;
        right=NULL;
    }
};

node* buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

class HBPair{
public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(node*root)
{
    HBPair p;
    if(root==NULL)
    {
        p.height=0;
        p.balance=true;
        return p;
    }
    //rec
    //postorder bottom up
    HBPair left=isHeightBalanced(root->left);
    HBPair right=isHeightBalanced(root->right);

    p.height=max(left.height,right.height) + 1;
    if(abs(left.height - right.height)<=1 && left.balance && right.balance)
    {
        p.balance=true;
    }
    else
    {
        p.balance=false;
    }
    return p;
}

int main()
{
    node*root=buildTree();
    if(isHeightBalanced(root).balance)
    {
        cout<<"balanced";
    }
    else
    {
        cout<<"not a balanced tree";
    }
    return 0;
}
