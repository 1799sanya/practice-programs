#include<iostream>
using namespace std;

int main()
{
    int n;
    int a[1000];
    cin>>n;

    int no;
    int res=0;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        a[i]=no;
        res=res^no;
    }
    //res=a^b
    int temp=res;
    int pos=0;
    while((temp&1)!=1)
    {
        pos++;
        temp=temp>>1;
    }
    //the first set bit in res is at position 'pos'
    int x=0;
    int y=0;
    int mask=(1<<pos);
    //find those nos which contain set bit at pos
    for(int i=0;i<n;i++)
    {
        if((a[i]&mask)>0)
        {
            x=x^a[i];
        }
    }
    y=x^res;

    cout<<min(x,y)<<" "<<max(x,y)<<endl;
    return 0;
}
