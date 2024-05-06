#include<iostream>
using namespace std;
int main()
{
	int a[100],n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
	if(a[i]!=a[n-i-1])
	{
		cout<<"NO";	
		return 0;
	}
	
	}
	cout<<"YES";
	return 0;
}
