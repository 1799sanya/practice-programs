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

void printRightView(node*root,int level,int &maxlevel)
{
    if(root==NULL)
    {
        return;
    }
    if(maxlevel<level)
    {
        //we have discovered a new level and this is the first node of this level which has to be printed
        //as we are traversing from right to left
        cout<<root->data<<" ";
        maxlevel=level;
    }
    //right
    //left
    printRightView(root->right,level+1,maxlevel);
    printRightView(root->left,level+1,maxlevel);
}

int main()
{
    node*root=buildTree();
    int maxlevel=-1;
    printRightView(root,0,maxlevel);
    return 0;
}
