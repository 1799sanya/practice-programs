#include<iostream>
using namespace std;

int ways(int n)
{
    //base
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 2;
    }
    //rec
    return ways(n-1)+ways(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<ways(n);
    return 0;
}
