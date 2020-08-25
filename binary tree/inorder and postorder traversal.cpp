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
void printPre(node*root)
{
    if(root==NULL)
    {
        return;
    }
    //root left right
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(node*root)
{
    if(root==NULL)
    {
        return;
    }
    //left root right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printPost(node*root)
{
    if(root==NULL)
    {
        return;
    }
    //left right root
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node*root=buildTree();
    printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPost(root);
    return 0;
}
