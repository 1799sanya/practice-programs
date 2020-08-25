#include<iostream>
#include<unordered_set>
using namespace std;

int findUnion(int a[],int b[],int m,int n)
{
    unordered_set<int> s;
    for(int i=0;i<m;i++)
    {
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        s.insert(b[i]);
    }
    return s.size();
}

int main()
{
    int m,n;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cout<<findUnion(a,b,m,n);
    return 0;
}
