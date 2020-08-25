#include<iostream>
using namespace std;
#define ll long long
void prime_sieve(int *p)
{
	//make all odd nos prime
	for(int i=3;i<=1000005;i+=2)
	{
		p[i]=1;
	}
	//sieve
	//jumping over odd nos
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
}

int main() {
	int n;
	cin>>n;
	int p[1000005]={0};
	prime_sieve(p);
	int count=0;
	for(int i=0;i<=1000005;i++)
	{
		if(p[i]==1)
		{
			count++;
			if(count==n)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
