#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s,int x)
{
    //base
    if(s.empty())
    {
        s.push(x);
        return;
    }
    //rec
    int data=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
}

void reverseStack(stack<int>&s)
{
    //base
    if(s.empty())
    {
        return;
    }
    //o/w
    //pop out the top element and insert it at bottom of 'smaller reversed stack'
    int x=s.top();
    s.pop();
    //recursively reverse the smaller stack
    reverseStack(s);
    insertAtBottom(s,x);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
