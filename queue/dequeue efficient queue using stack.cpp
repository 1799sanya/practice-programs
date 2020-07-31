#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            exit(0);    // don't return -1. it is not specified in question to return -1 when empty
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    int n;
    cin>>n;
    int m=n;
    for(int i=0;i<n;i++){
        q.enQueue(i);
    }

    for(int i=0;i<m;i++)
    {
         cout<<q.deQueue()<<" ";  // here also i have modified changed the code instead of -1.
    }

     cout<<endl;

    return 0;
}
