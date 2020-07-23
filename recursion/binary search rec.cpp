#include<iostream>
using namespace std;

int binarySearch(int a[],int s,int e,int key)
{
    if(s<=e)
    {
        int mid=(s+e)/2;
        //base case
        if(a[mid]==key)
        {
            return mid;
        }
        //rec case
        if(a[mid]>key)
        {
            return binarySearch(a,s,mid-1,key);
        }
        else{
            return binarySearch(a,mid+1,e,key);
        }
    }
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,10,20};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    cout<<binarySearch(a,0,n-1,key)<<endl;
    return 0;
}
