#include<iostream>
using namespace std;

//PASS BY VALUE
/*void increment(int a)
{
    a=a+1;
    cout<<"Inside function:"<<a<<endl;  //output -> 11
}

int main()
{
    int a=10;
    increment(a);
    cout<<"Inside main:"<<a<<endl;  //output -> 10
    return 0;
}
*/

//PASS BY REFERENCE USING POINTERS
void increment(int *aptr)
{
    *aptr = *aptr + 1;
    cout<<"Inside function:"<<*aptr<<endl;
}
int main()
{
    int a=10;
    increment(&a);
    cout<<"Inside main:"<<a<<endl;
    return 0;
}
