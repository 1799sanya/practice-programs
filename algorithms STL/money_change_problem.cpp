#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b)
{
    return a<=b;
}

int main()
{
    //Indian Money Change
    //make a change for a given amount using minimum number of coins
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(coins)/sizeof(int);
    int money=168;
    //look at the coin which offers you the highest value but is less than 168
    //168-100=68
    //68-50=18
    //18-10=8 and so on
    //using binary search(sorted) and lower_bound()

    while(money>0)
    {
        //overwritten the default functionality of lower_bound fun using the compare function
        int lb = lower_bound(coins,coins+n,money,compare) - coins - 1;
        //cout<<lb<<" value "<<coins[lb];
        int m=coins[lb];
        cout<<m<<", ";
        money = money - m;
    }



    return 0;

}
