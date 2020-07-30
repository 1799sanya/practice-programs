#include<iostream>
#include<vector>
using namespace std;

//generalized code for all data types using templates
template<typename T>
class Stack{
private:
    vector<T> v;
public:
    void push(T data)
    {
        v.push_back(data);
    }
    bool empty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!empty())
        {
            v.pop_back();
        }
    }
    T top()
    {
        return v[v.size()-1];
    }
};

int main()
{
    Stack<char> s;  //T is defined when stack object is defined
    for(int i=65;i<=70;i++)
    {
        s.push(i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
