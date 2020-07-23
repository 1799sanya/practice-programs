//pair container binds 2 values into a single value
#include<iostream>
using namespace std;

int main()
{
    //Pair
    pair<int,char> p;
    p.first = 10;
    p.second = 'B';

    //Another way
    pair<int,char> p2(p);

    cout<<p2.first<<endl;
    cout<<p2.second<<endl;

    //using make_pair function
    pair<int,string> p3 = make_pair(100,"Audi");
    cout<<p3.first<<" "<<p3.second;
    return 0;
}
