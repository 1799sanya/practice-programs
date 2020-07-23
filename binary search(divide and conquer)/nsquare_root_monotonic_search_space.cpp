#include<iostream>
using namespace std;

int square_root(int n)
{
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if((mid*mid) == n)
        {
            return mid;
        }
        if((mid*mid)<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    cout<<square_root(n)<<endl;
    return 0;
}
