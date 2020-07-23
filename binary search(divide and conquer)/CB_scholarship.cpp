#include<iostream>
using namespace std;

bool isPossible(int n,int m,int x,int y,int curr_students)
{
	//requirement<=availibility
	if((curr_students*x)<=(m + (n-curr_students)*y))
	{
		return true;
	}
	else{
		return false;
	}
}

int cb_scholarship(int n,int m,int x,int y)
{
	long long int s=0;
	long long int e=n; //search space
	long long int ans=0;
	while(s<=e)
	{
		long long int mid=(s+e)/2;
		if(isPossible(n,m,x,y,mid))
		{
			ans=max(mid,ans);
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	return ans;
}
int main() {
	long long int n,m,x,y;
	cin>>n>>m>>x>>y;

	cout<<cb_scholarship(n,m,x,y)<<endl;

	return 0;
}
