#include<iostream>
using namespace std;

int lastOcc(int a[],int n,int key)
{
    //base
    if(n==0)
    {
        return -1;

    }
    //rec case
    int i=lastOcc(a+1,n-1,key);
    if(i==-1)
    {
        if(a[0]==key)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    //otherwise if i returned by subproblem is not -1
    return i+1;
}

int findOcc(int a[],int n,int key)
{
    //base case
    if(n==0)
    {
        return -1;
    }
    //rec case
    if(a[0]==key)
    {
        return 0;
    }
    int i=findOcc(a+1,n-1,key);
    if(i==-1)
    {
        return -1;
    }
    return i+1;
}

//different style of writing the same function
int linearSearch(int a[],int i,int n,int key)
{
    //base case
    if(i==n)
    {
        return -1;
    }
    //rec case
    if(a[i]==key)
    {
        return i;
    }
    return linearSearch(a,i+1,n,key);
}

int main()
{
    int a[]={1,2,3,7,4,5,6,7,10};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    cout<<findOcc(a,n,key)<<endl;
    cout<<linearSearch(a,0,n,key)<<endl;
    cout<<lastOcc(a,n,key)<<endl;
    return 0;
}
