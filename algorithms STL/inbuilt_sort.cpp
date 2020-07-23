#include<iostream>
#include<algorithm>
using namespace std;

//to sort elements in decreasing order
//we have to define a comparator function
bool compare(int a,int b)
{
    cout<<"comparing "<<a<<" and "<<b<<endl;
    return a<b; // for inc order return a>b
}

int main()
{
    int n;
    cin>>n;
    int a[1000];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //sort an array using sort function
    //without compare it will sort the array in inc order
    sort(a,a+n,compare); //add compare when you want in dec order
    //passing a function as a parameter to another function

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<", ";
    }
    return 0;
}
