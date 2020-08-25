#include<iostream>
#include<unordered_set>
using namespace std;

bool isSum(int a[],int n)
{
    unordered_set<int> s;
    int pre_sum=0;
    for(int i=0;i<n;i++)
    {
        pre_sum=pre_sum+a[i];
        if(s.find(pre_sum)!=s.end())
        {
            return true;
        }
        if(pre_sum==0)
        {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
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
    cout<<isSum(a,n);
    return 0;
}
