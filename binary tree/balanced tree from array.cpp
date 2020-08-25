#include<iostream>
#include<queue>
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

node* buildTreeFromArray(int a[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(a[mid]);
    root->left=buildTreeFromArray(a,s,mid-1);
    root->right=buildTreeFromArray(a,mid+1,e);
    return root;
}

void bfs(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*f=q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
}


int main()
{

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    node*root=buildTreeFromArray(a,0,n-1);
    bfs(root);
    return 0;
}
