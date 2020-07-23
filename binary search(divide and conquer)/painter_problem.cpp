#include <iostream>
#define ll long long int
using namespace std;


bool isgood(ll ar[],ll n, ll k ,ll cut)
{
    ll pcnt=1,ucnt=0;
    for(ll i=0;i<n;i++)
    {
        if(ar[i]>cut)
        {
            return false;
        }
        if((ucnt+ar[i])<=cut)
        {
            ucnt+=ar[i];
        }
        else
        {
            pcnt++;
            ucnt=ar[i];
            if(pcnt>k)
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ll n,k,t;
    cin>>n>>k>>t;
    ll ar[n];
    for(ll i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    ll sum=0,max=ar[0];
    for(ll i=0;i<n;i++)
    {
		if(ar[i]>max)
		{
			max=ar[i];
		}
        sum+=ar[i];
    }
    ll s=max,l=(sum),ans;
    while(s<=l)
    {
        ll mid=(s+l)/2;
        if(isgood(ar,n,k,mid))
        {
            ans=min(ans,mid);
            l=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<((ans%10000003)*t)%10000003<<endl;
}
