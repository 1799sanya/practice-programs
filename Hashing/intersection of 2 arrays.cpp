#include<iostream>
#include<unordered_set>
using namespace std;

int intersection(int a[],int b[],int m,int n)
{
    unordered_set<int> s;
    for(int i=0;i<m;i++)
    {
        s.insert(a[i]);
    }
    int res=0;
    for(int j=0;j<n;j++)
    {
        if(s.find(b[j])!=s.end())
        {
            res++;
            s.erase(b[j]);
        }
    }
    return res;
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

    cout<<intersection(a,b,m,n);
    return 0;
}
