#include<iostream>
using namespace std;
int main()
{
	long long a[100],n,k,m=0;
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		m=m+a[i];
	}
	cout<<m;
	cout<<endl; 
	cout<<a[k-1];
	return 0;
}

