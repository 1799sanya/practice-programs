#include<iostream>
using namespace std;

void Move(int n,char src,char helper,char dest)
{
    //base
    if(n==0)
    {
        return;
    }
    //rec
    //move n-1 disks from src to helper
    Move(n-1,src,dest,helper);
    //move nth disk from src to dest
    cout<<"shift disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    //move n-1 disks from helper to dest
    Move(n-1,helper,src,dest);
}

int main()
{
    int n;
    cin>>n;

    Move(n,'A','B','C');
    return 0;
}
