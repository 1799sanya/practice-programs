#include<iostream>
using namespace std;

int first_occurence(int arr[],int n,int key)
{
    int s=0;
    int e=n-1;
    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key)
        {
            ans = mid;
            e=mid-1; //don't stop but explore the left part of the array
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int last_occurence(int arr[],int n,int key)
{
    int s=0;
    int e=n-1;
    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key)
        {
            ans = mid;
            s=mid+1; //don't stop but explore the right part of the array
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int arr[]={1,2,5,8,8,8,8,10,12};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;

    cout<<first_occurence(arr,n,key)<<endl;
    cout<<last_occurence(arr,n,key)<<endl;

    return 0;
}
