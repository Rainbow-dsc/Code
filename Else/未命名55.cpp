#include<iostream>
using namespace std;
int main()
{
	int a,b,MAX=0;
	cin>>a>>b;
	if(a==b)
	{
		cout<<b;
	}
	else
	{
	MAX=a>b?a:b;
		cout<<MAX;
	}
	return 0;
}

