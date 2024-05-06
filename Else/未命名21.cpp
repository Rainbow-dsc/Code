#include<iostream>
using namespace std;
int main()
{
	int n,m=0,s=0,a=0,b;
	cin>>n;
	for(;n>0;n=n/10)
	{
		a=n%10;
		if(a>m)
		{
			s=m;
			m=a;
		}
		else if(a>s)
		{
			s=a;
		}
	}
	b=s+m;
	cout<<b;
	return 0;
}

