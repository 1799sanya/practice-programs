#include<iostream>
#include<cstring>
using namespace std;
#define ll long
ll a[1000005],pre[1000005];

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(pre,0,sizeof(pre));
		int sum=0;
		pre[0]=1; //sum of null subarray in beginning
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			sum%=n;
			sum=(sum+n)%n;
			pre[sum]++; //frequency update
		}
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			ll m=pre[i];
			ans+=((m)*(m-1))/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
