#include<iostream>
using namespace std;

#define ll long long

//naive approach
/*bool isPrime(int n)
{
    if(n==1)
    {
        return false;
    }
    if(n==2)
    {
        return true;
    }
    for(int i=2;i<n;i++)
    {
        if((n%i)==0)
        {
            return false;
        }
    }
    return true;
}*/

void prime_sieve(int *p)
{
	for(int i=3;i<=100000;i+=2)
	{
		p[i]=1;
	}
	//sieve
	//jumping over all odd nos
	for(ll i=3;i<=100000;i+=2)
	{
		//if i is not marked->prime
		//mark all multiples of i as not prime
		if(p[i]==1)
		{
			for(ll j=i*i;j<=100000;j=j+i)
			{
				p[j]=0;
			}
		}
	}
	//special cases
	p[2]=1;
	p[1]=p[0]=0;
}

int main () {
	int n;
	cin>>n;
	int p[100005]={0};
	prime_sieve(p);
	int count=0;
	for(int i=0;i<=n;i++)
	{
		if(p[i]==1)
		{
			count=count+1;
			if(count==1)
			{
				cout<<i;
			}
			else
			{
				cout<<", "<<i;
			}
		}
	}
	return 0;
}
