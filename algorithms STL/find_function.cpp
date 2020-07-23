#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[]={1,10,11,9,100};
    int n=sizeof(arr)/sizeof(int);
    //Search --> find
    int key;
    cin>>key;
    auto it = find(arr,arr+n,key);
    cout<<it<<endl; //returns an address
    int index= it - arr; //in c++ if we subtract 2 pointers we get the number of blocks between them
    if(index==n)
    {
        cout<<key<<" not found"<<endl;
    }
    else{
        cout<<"key found at "<<index<<endl;
    }

    return 0;
}
