#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a>=0&&a<10)
	{
		cout<<1;
	}
	if(a>=10&&a<100)
	{
		cout<<2;
	}
	if(a>=10&&a<1000)
	{
		cout<<3;
	}
	return 0;
}

