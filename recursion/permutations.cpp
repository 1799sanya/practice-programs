#include<iostream>
#include<string>
#include<set>
using namespace std;

void permute(char in[],int i,set<string> &s)
{
    //base
    if(in[i]=='\0')
    {
        //cout<<in<<" ";
        string t(in);
        s.insert(t);
        return;
    }
    //rec
    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        permute(in,i+1,s);
        //backtracking-> to restore the original array
        swap(in[i],in[j]);
    }
}

int main()
{
    char in[100];
    cin>>in;
    set<string> s;

    permute(in,0,s);

    //loop over the set
    for(auto str:s)
    {
        cout<<str<<", ";
    }
    return 0;
}
