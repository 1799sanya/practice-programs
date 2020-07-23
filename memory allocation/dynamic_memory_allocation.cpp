#include<iostream>
using namespace std;

int main()
{
    //Static Allocation + Deallocation = compiler
    int b[100];
    //this array is deleted automatically once it is out of scope or function call is over
    cout<<sizeof(b)<<endl; //output -> 400(b represents entire array)
    cout<<b<<endl; //symbol table
    //here b cant be overwritten, it is a part of read only memory

    //Dynamic Allocation(on the run time/on the fly)
    int n;
    cin>>n;
    int *a= new int[n];
    cout<<sizeof(a)<<endl;  //gives size of only the pointer variable(a only represents starting address of array)
    cout<<a<<endl; //variable a that is created inside the static memory -> overwritten
    //a= new char[30]

    //No change
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }

    //Free up the space to avoid any memory leak
    delete [] a;
}
