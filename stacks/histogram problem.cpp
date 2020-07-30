#include<iostream>
#include<stack>
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  long long int a[n];
  for(long long int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  long long int max=0;
  long long int step_area;
  long long int tp;
  stack<long long int>p;
  long long int i=0;
  while(i<n)
  {
    if(p.empty() || a[p.top()]<=a[i])
    {
      p.push(i++);
    }
    else
    {
      tp=p.top();
      p.pop();
      if(p.empty())
      {
        step_area=a[tp]*i;
      }
      else
      if(!p.empty())
      {
        step_area=a[tp]*(i-p.top()-1);
      }
      if(step_area>max)
      {
        max=step_area;
      }
    }
  }
  while(!p.empty())
  {
    tp=p.top();
    p.pop();
    if(p.empty())
    {
      step_area=a[tp]*i;
    }
    else
    if(!p.empty())
    {
      step_area=a[tp]*(i-p.top()-1);
    }
    if(step_area>max)
    {
      max=step_area;
    }
  }
  cout<<max;
	return 0;
}
