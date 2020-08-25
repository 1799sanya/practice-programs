#include<iostream>
#include<unordered_set>
using namespace std;

int countDistinct(int a[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    return s.size();
}

int main()
{
    int a[]={15,12,13,12,13,13,18};
    int n=sizeof(a)/sizeof(int);
    cout<<countDistinct(a,n);
    return 0;
}
