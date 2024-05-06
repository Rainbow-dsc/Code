#include <iostream>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(n<m)
	{
		for(int i=1;i<=n;i++)
		{
			if(n%i==0&&m%i==0)
			{
			cout<<i<<" ";
			}
		}
	}
	else
		{
			for(int i=1;i<=m;i++)
			{
				if(n%i==0&&m%i==0)
				{
				cout<<i<<" ";
				}		
			}
		}
	return 0;
}


