#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[10],n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		a[n+i]=k; 
	}
	sort(a,a+(n+m+1));
	for(int i=1;i<=(n+m);i++)
	{
		cout<<a[i]<<' '; 
	} 
	return 0;
}


