#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int price[],int n,int span[])
{
    stack<int> s; // storing indices of days
    s.push(0); //index of day 0
    span[0]=1;

    //loop for rest of the days
    for(int i=1;i<=n-1;i++)
    {
        int currentPrice=price[i];
        //topmost element that is higher than current price
        while(!s.empty() && price[s.top()]<=currentPrice)
        {
            s.pop();
        }
        if(!s.empty())
        {
            int prev_highest=s.top();
            span[i]=i-prev_highest;
        }
        else{
            span[i]=i+1;
        }
        //push this element into the stack
        s.push(i);
    }
}

int main()
{
    int price[]={100,80,60,70,60,75,85};
    int n=sizeof(price)/sizeof(int);
    int span[100]={0};
    stockSpan(price,n,span);
    for(int i=0;i<n;i++)
    {
        cout<<span[i]<<" ";
    }
    return 0;
}
