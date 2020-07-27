#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;

    //init
    list<int> l1{1,2,3,10,8,5};
    //different data type
    list<string> l2{"apple","guava","mango","banana"};
    l2.push_back("pineapple");

    //sorting
    l2.sort();

    //reverse
    l2.reverse();

    //pop_front
    cout<<l2.front()<<endl;
    l2.pop_front();

    //add to the front of the list
    l2.push_front("kiwi");
    cout<<l2.back()<<endl;
    l2.pop_back();

    //iterate over the list and print the data
    for(auto it=l2.begin();it!=l2.end();it++)
    {
        cout<<(*it)<<"-->";
    }
    cout<<endl;

    //some more functions
    l2.push_back("orange");
    l2.push_back("guava");
    for(auto s:l2)
    {
        cout<<s<<"-->";
    }
    //remove a fruit by value
    //string f;
    //cin>>f;
    //l2.remove(f);
    for(auto s:l2)
    {
        cout<<s<<"-->";
    }
    cout<<endl;

    //erase one or more element
    auto it=l2.begin();
    it++;
    it++;
    l2.erase(it); //remove second element
    for(auto s:l2)
    {
        cout<<s<<"-->";
    }
    cout<<endl;
    //insert element in list
    it=l2.begin();
    it++;
    l2.insert(it,"juice");
    for(auto s:l2)
    {
        cout<<s<<"-->";
    }


    return 0;
}

