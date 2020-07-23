#include<iostream>
using namespace std;

void Merge(int a[],int s,int e)
{
    int mid=(s+e)/2;

    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100];

    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }
    //we need to copy all elements to original array
    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];
    }
}

void mergeSort(int a[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }
    //rec case
    //follow 3 steps
    //1.divide
    int mid=(s+e)/2;
    //2.recursively sort the 2 arrays->(s,mid) and (mid+1,e)
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    //3.merge the 2 arrays
    Merge(a,s,e);
}

int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
