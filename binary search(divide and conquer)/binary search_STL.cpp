#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[]={20,30,40,40,40,50,100,1100};
    int n=sizeof(a)/sizeof(int);
    //search in a sorted array
    int key;
    cin>>key;

    bool present = binary_search(a,a+n,key);
    if(present)
    {
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }

    //get the index of the element
    //lower_bound(s,e,key) and upper_bound(s,e,key) -> returns address where element is stored

    auto lb = lower_bound(a,a+n,40); //returns the address of the first bucket which is greater than or equal to 40
    //first occurence of element 40
    //to get the index
    cout<<"lowerbound of 40: "<<(lb-a)<<endl;

    //upper bound method
    auto ub = upper_bound(a,a+n,40);
    cout<<"upperbound of 40: "<<(ub-a)<<endl;

    cout<<"occurence frequency of 40 is:"<<(ub-lb)<<endl;


    return 0;
}
