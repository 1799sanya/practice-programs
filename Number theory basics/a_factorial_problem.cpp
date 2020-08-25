#include<iostream>
using namespace std;
#define INT_MAX 100000000

int main() {
	int t;
	cin>>t;
	int n,k;
	while(t--)
	{
		cin>>n>>k;
		int ans=INT_MAX;
		//factorization of k
		//p1,p2,..pl
		for(int i=2;i*i<=k;i++)
		{
			if(k%i==0)
			{
				int occ=0;
				while(k%i==0)
				{
					occ++;
					k=k/i;
				}
				//find out powers of i in n! side by side
				int cnt=0;
				long long p=i;
				while(p<=n)
				{
					cnt+=n/p;
					p=p*i;
				}
				ans=min(ans,cnt/occ);
			}
		}
		//we may have a case when still a prime factor is left
		if(k>1)
		{
			//occ=1;
			long long p=k;
			int cnt=0;
			while(p<=n)
			{
				cnt+=n/p;
				p=p*k;
			}
			ans=min(ans,cnt);
		}
		//if prime factors of k dont exist in n!
		if(ans==INT_MAX)
		{
			ans=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
