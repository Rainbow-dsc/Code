#include<iostream>
using namespace std;
int n,a[100000];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cout<<a[2]-a[1]<<' '<<a[n]-a[1]<<endl;
		}
		else if(i==n)
		{
			cout<<a[n]-a[n-1]<<' '<<a[n]-a[1]<<endl;
		}
		else 
			cout<<min(a[i]-a[i-1],a[i+1]-a[i])<<' '<<max(a[i]-a[1],a[n]-a[i])<<endl;
		
	}
	return 0;
}


