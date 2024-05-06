#include<iostream>
using namespace std;
int main()
{
	int a[10],n;
	for(int i=1;i<=6;i++)
	{
		cin>>a[i];
	} 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int k=0;
		cin>>k;
		a[k]+=5; 
	}
	for(int i=1;i<=6;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}


