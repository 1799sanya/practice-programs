#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[]={20,30,40,40,50,100,1100};
    int n=sizeof(arr)/sizeof(int);
    //Search in a sorted array
    int key;
    cin>>key;

    bool present = binary_search(arr,arr+n,key);
    if(present)
    {
        cout<<"present"<<endl;

    }
    else{
        cout<<"absent"<<endl;
    }
    //get the index of the element
    // lower_bound(s,e,key) and upper_bound(s,e,key)
    //lower_bound() gives first element index which is >= to the key

    auto lb = lower_bound(arr,arr+n,40);
    cout<<"lower bound of 40 is "<<(lb-arr)<<endl;

    //upper bound method gives first element index which is strictly greater than key
    auto ub = upper_bound(arr,arr+n,40);
    cout<<"upper bound of 40 is "<<(ub-arr)<<endl;

    cout<<"occurrence frequency of 40 is: "<<(ub-lb)<<endl;

    return 0;
}
