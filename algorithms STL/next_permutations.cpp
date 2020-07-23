#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {10,20,30,40,50};
    int n=sizeof(arr)/sizeof(int);
    //to rotate the array from the middle element
    rotate(arr,arr+2,arr+n);

    //rotated array
    //30,40,50,10,20
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    //Apply the same on vector
    vector<int> v{10,20,30,40,50};
    //rotate about the third element
    //40,50,10,20,30
    rotate(v.begin(),v.begin()+3,v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<", ";
    }

    //Next permutation
    next_permutation(v.begin(),v.end());
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<", ";
    }
    return 0;
}
