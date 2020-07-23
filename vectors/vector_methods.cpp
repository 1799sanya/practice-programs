#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> d{1,2,3,10,12};
    //push back O(1) for most of the time
    d.push_back(16);

    //pop back -> removes the last element O(1)
    d.pop_back();

    //insert some elements in the middle of the vector
    //specify the position where you want to insert
    d.insert(d.begin()+3,4,100); //4 specifies the no of elements you want to add

    //erase some element from the middle O(n)
    d.erase(d.begin()+2);
    d.erase(d.begin()+2,d.begin()+5); //for erasing a range of elements

    //size
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl; //10 due to the use of push back

    //we avoid the shrink operation
    d.resize(18); //if size is increasing then more memory will be allocated
    cout<<d.capacity()<<endl;

    //remove all elements of vector, does not delete the memory occupied by the array
    d.clear();
    cout<<d.size()<<endl;

    if(d.empty())
    {
        cout<<"this is an empty vector"<<endl;
    }

    for(int x:d)
    {
        cout<<x<<",";
    }
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    cout<<d.front()<<endl; //gives the front element
    cout<<d.back()<<endl; //gives the last element

    //Reserve -> will not the change the capacity again and again until you reach the specified size
    //to avoid doubling we will use reserve function
    int n;
    cin>>n;
    vector<int> v;
    v.reserve(1000); //capacity will remain same until 1000 elements are filled
    //so no resizing and doubling again and again

    cout<<endl;
}
