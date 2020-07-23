#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> out;

void removeDuplicates(){

	for(int i=0;i<out.size();i++){

		string s=out[i];
		cout<<s<<" ";
        while(out[i]==s){
			i++;
		}
        i=i-1;
	}
}

void permute(char in[],int i)
{
	//base
	if(in[i]=='\0')
	{
		out.push_back(in);
		//count++;
		return;
	}
	//rec
	for(int j=i;in[j]!='\0';j++)
	{
		swap(in[i],in[j]);
		permute(in,i+1);
		//backtracking-> to restore the original array
		swap(in[i],in[j]);
	}
}

int fact(int n)
{
	//base
	if(n==0 || n==1)
	{
		return 1;
	}
	//rec
	return n*fact(n-1);
}

int main() {
	char in[1000];
	cin>>in;
	int len=strlen(in);
	int count=fact(len);
	cout<<count<<endl;
	//sort(out.begin(),out.end());
   // removeDuplicates();
	permute(in,0);
	sort(out.begin(),out.end());
	removeDuplicates();
	return 0;
}
