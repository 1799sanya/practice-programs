#include<iostream>
using namespace std;

int main()
{
    //&bucket -> address
    //*address -> bucket
    int x=10;
    int *xptr;
    xptr=&x;

    cout<<&x<<endl;
    cout<<xptr<<endl;

    cout<<*(&x)<<endl;
    cout<<*(xptr)<<endl;

    cout<<*(&xptr)<<endl;
    cout<<&(*xptr)<<endl;

    cout<<&xptr<<endl;
    //double pointer
    int **xxptr=&xptr;
    cout<<xxptr;

    return 0;
}
