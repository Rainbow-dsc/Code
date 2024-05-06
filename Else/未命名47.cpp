#include<iostream>
using namespace std;
int main()
{
	int n,a=0,b;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j*j)
			{
				a+=i;
			}
		} 
	}
	cout<<a;
	return 0;
}

