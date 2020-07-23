#include<iostream>
using namespace std;

int fact(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }

    //recursive case
    int small_ans = fact(n-1);
    return n*small_ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}
