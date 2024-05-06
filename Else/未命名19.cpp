#include<iostream>
using namespace std;
int main()
{
	int n,s=1;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			s=s+i;
		}
		else
		{
			s=s-i;
		}
	}
	cout<<s;
	return 0;
}

