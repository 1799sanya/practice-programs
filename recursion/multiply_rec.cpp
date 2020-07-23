//write a recursive function to multiply 2 nos (a,b) w/o using the * operator
#include<iostream>
using namespace std;

int multiply(int a,int b)
{
    //base case
    if(b==1)
    {
        return a;
    }
    //rec case
    return (a+multiply(a,b-1));
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<multiply(a,b)<<endl;
    return 0;
}
