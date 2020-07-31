#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[1000000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	//we have to process the first k elements separately
	deque<int> Q(k);
	int i;
	for(i=0;i<k;i++)
	{
		while(!Q.empty() && a[i]>a[Q.back()])
		{
			Q.pop_back();
		}
		Q.push_back(i);
	}
	//process the remaining elements
	for(;i<n;i++)
	{
		cout<<a[Q.front()]<<" ";
		//1. remove the elements which are not the part of the window
		while(!Q.empty() && (Q.front()<=i-k))
		{
			Q.pop_front();
		}
		//2. remove the elements which are not useful and in the window
		while(!Q.empty() && a[i]>=a[Q.back()])
		{
			Q.pop_back();
		}
		//3. add the new elements
		Q.push_back(i);
	}
	//last element
	cout<<a[Q.front()]<<endl;
	return 0;
}
