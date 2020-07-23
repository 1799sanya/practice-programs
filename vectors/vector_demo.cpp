#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //ways in which you can create and initialize a vector
    vector<int> a; //all elements of this dynamic array would be of type int
    vector<int> b(5,10); //5 integers in the array and they have a value 10
    //useful when you want to initialize a vector of zeros (n,0)
    vector<int> c(b.begin(),b.end()); //copy all elements of vector b to c
    vector<int> d{1,2,3,10,14};

    //iterate over the vector
    //size method defines how many elements your vector is going to contain
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i]<<", ";
    }
    cout<<endl;

    //another way
    //it is like a pointer which will iterate over different locations in dynamic array
    //iterator is defined in the vector class
    for(auto it=b.begin();it!=b.end();it++)
    {
        cout<<(*it)<<", ";
    }
    cout<<endl;

    //another way -> using for each loop
    for(int x:d)
    {
        cout<<x<<", ";
    }
    cout<<endl;

    //more functions
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
        //push_back() adds an element to the end of the vector and also expands the memory if needed
        //in push back repeated doubling of memory happens
        //doubling of memory is an expensive operation
    }
    for(int x:v)
    {
        cout<<x<<", ";
    }
    cout<<endl;

    //understand at memory level what are the differences between the 2 vectors v
    cout<<v.size()<<endl; //5
    cout<<v.capacity()<<endl; //size of underlying array ->ans= 8 (due to doubling of size because of push back)
    cout<<v.max_size()<<endl; //max no of elements a vector can hold in the worst case according to available memory in system

    cout<<d.size()<<endl; //5
    cout<<d.capacity()<<endl; //5
    cout<<d.max_size()<<endl;


    return 0;
}
