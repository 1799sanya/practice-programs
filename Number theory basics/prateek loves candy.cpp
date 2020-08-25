#include<iostream>
using namespace std;
#define ll long long
long long a[1000000];

void prime_sieve(int *p)
{
	for(int i=3;i<=1000005;i+=2)
	{
		p[i]=1;
	}
	for(ll i=3;i<=1000005;i+=2)
	{
		if(p[i]==1)
		{
			for(ll j=i*i;j<=1000005;j+=i)
			{
				p[j]=0;
			}
		}
	}
	p[2]=1;
	p[0]=p[1]=0;

	int k=0;
	for(int i=2;i<=1000005;i++)
	{
		if(p[i]==1)
		{
			a[k]=i;
			k++;
		}
	}
	return;
}

int main() {
	int p[1000005]={0};
	prime_sieve(p);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<a[n-1]<<endl;
	}
	return 0;
}
