#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    //base
    if(q.empty())
    {
        return;
    }
    //base
    int d=q.front();
    q.pop();
    reverseQueue(q);

    q.push(d);
}

int main()
{
    queue<int> q;
    int n;
    cin>>n;
    int data;
    while(n--)
    {
        cin>>data;
        q.push(data);
    }
    reverseQueue(q);
    while(n--)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
