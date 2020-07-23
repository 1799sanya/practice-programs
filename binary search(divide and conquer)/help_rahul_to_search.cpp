//apply binary search on a sorted rotated array
#include<iostream>
using namespace std;

int find_key(int a[],int n,int key)
{
    //for finding element in a rotated array formed from a sorted array
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(key==a[mid])
        {
            return mid;
        }
        else if(a[s]<=a[mid])
        {
            //mid point lying on the first part
            //2 cases-> element lies on the left or on the right of the mid
            if(key>=a[s] && key<=a[mid])
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        else
        {
            //mid point lying on the other part of the array
            if(key>=a[mid] && key<=a[e])
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<find_key(a,n,key)<<endl;
    return 0;
}
