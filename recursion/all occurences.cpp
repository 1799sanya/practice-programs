#include<iostream>
using namespace std;

void allOcc(int a[],int i,int n,int key)
{
    //base case
    if(i==n)
    {
        return;
    }
    //rec case
    if(a[i]==key)
    {
        cout<<i<<",";
    }
    allOcc(a,i+1,n,key);
}

int main()
{
    int a[]={1,2,3,7,4,5,6,7,10};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    allOcc(a,0,n,key);
    cout<<endl;
    return 0;
}
