#include<iostream>
using namespace std;
int main()
{
	int n,m,a;
	cin>>n>>m;
	for(int i=1;i<=m&&i<=n;i++)
	{
	if(m%i==0&&n%i==0)
	{
		a=i;
	}		
	}
	cout<<a<<" ";
	return 0;
}

