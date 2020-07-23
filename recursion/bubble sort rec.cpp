#include<iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    //base
    if(n==1)
    {
        return;
    }
    //rec
    for(int j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    bubbleSort(a,n-1);
}

int main()
{
    int a[]={5,4,2,3,1};
    int n=5;
    bubbleSort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
