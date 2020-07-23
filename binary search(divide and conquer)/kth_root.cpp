#include<iostream>
#include<math.h>
using namespace std;
int main() {
  long long int t;
  cin>>t;
  long long int ans,d;
  long int n,i,k;
  long int s,e,m;
  for(i=0;i<t;i++)
  {
    cin>>n>>k;
    s=0;
    e=n-1;
    ans=0;
    while(s<=e)
    {
      m=(s+e)/2;
      d=m+1;  //take this 1 greater than mid
      //cout<<"d->"<<d<<endl;
      if(pow(d,k)==n)
      {
      	ans=d;

      	break;
	  }
      else if(pow(d,k)>n)
      {
        e=m-1;
      }
      else if(pow(d,k)<n)
      {
        ans=d;
        s=m+1;
      }
    }
    cout<<ans<<endl;
  }
	return 0;
}
