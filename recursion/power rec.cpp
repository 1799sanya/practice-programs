//write a recursive function to perform power(a,n)
//time and space complexity-> O(n)
#include<iostream>
using namespace std;

int power_rec(int a,int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    //rec case
    return a*power_rec(a,n-1);

}

int main()
{
    int a,n;
    cin>>a>>n;
    cout<<power_rec(a,n);
    return 0;

}
