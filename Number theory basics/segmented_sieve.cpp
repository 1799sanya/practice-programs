#include<iostream>
#include<vector>
using namespace std;

const int N=100000;
vector<int> primes;
int p[N]={0};

void sieve()
{
	//constructing the primes array
	for(int i=2;i<=N;i++)
	{
		if(p[i]==0)
		{
			//store i in primes vector
			primes.push_back(i);
			//mark all multiples of i as not prime
			for(int j=i;j<=N;j+=i)
			{
				p[j]=1; //not prime
			}
		}
	}
}

int main() {
	//build this sieve only once for all the queries
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n; //m<n
		bool segment[n-m+1];
		for(int i=0;i<n-m+1;i++)
		{
			segment[i]=0;
		}

		//segment sieve logic
		for(auto x:primes)
		{
			//optimization
			//stop the loop if remaining prime nos are not needed
			if(x*x>n)
			{
				break;
			}
			int start=(m/x)*x;
			//if prime no lies in segment sieve range
			if(x>=m && x<=n)
			{
				start=x*2;
			}
			//mark all multiples of x, in range start to n as not prime
			for(int i=start;i<=n;i+=x)
			{
				segment[i-m]=1;//not prime
			}
		}
		//loop over range m..n and print the primes
		for(int i=m;i<=n;i++)
		{
			if(segment[i-m]==0 && i!=1)
			{
				cout<<i<<" ";
			}
			//cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}
