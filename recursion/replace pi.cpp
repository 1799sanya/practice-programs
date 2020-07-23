#include<iostream>
using namespace std;

void replacePi(char a[],int i)
{
    //base case
    if(a[i]=='\0' || a[i+1]=='\0')
    {
        return;
    }
    //rec case
    if(a[i]=='p' && a[i+1]=='i')
    {
        //shifting+replacement with 3.14
        int j=i+2;
        //take j to the end of the array
        while(a[j]!='\0')
        {
            j++;
        }
        //shifting(right to left)
        while(j>=(i+2))
        {
            a[j+2]=a[j];
            j--;
        }
        //replacement + rec call for remaining part
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        replacePi(a,i+4);
    }
    else{
        //go to the next position
        replacePi(a,i+1);
    }
}

int main()
{
    char a[10000];
    cin>>a;
    replacePi(a,0);
    cout<<a;
    return 0;
}
