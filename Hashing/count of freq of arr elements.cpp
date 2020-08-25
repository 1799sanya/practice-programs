#include<iostream>
#include<unordered_map>
using namespace std;

void countFreq(int a[],int n)
{
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for(auto x:mp)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main()
{
    int a[]={10,12,10,15,10,20,12,12};
    int n=sizeof(a)/sizeof(int);
    countFreq(a,n);
    return 0;

}
