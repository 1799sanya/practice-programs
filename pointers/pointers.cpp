#include<iostream>
using namespace std;

int main()
{
     int x=10;
    cout<<&x<<endl;

    float y=10.5;
    cout<<&y<<endl;

    //It does not work for character variables due to operator overloading
    char ch='A';
    cout<<&ch<<endl; //output->A
    //to correct it -> explicit typecasting from char* to void*
    //now cout does not know what type of address it is printing
    cout<<(void *)&ch<<endl;

    //pointers
    int *xptr;
    //stores the address of a variable
    xptr=&x;
    cout<<&x<<endl;
    cout<<xptr<<endl;

    //re assign another address to the variable
    int y1=20;
    xptr=&y1;
    cout<<&y1<<endl;
    cout<<xptr;
    return 0;
}
