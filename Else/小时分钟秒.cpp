#include<iostream>
using namespace std;
int a,b,c,d;
int main()
{
	cin>>a;
	b=a/3600;
	c=a%3600/60;
	d=a%3600%60;
	cout<<a<<"seconds="<<b<<"hours"<<c<<"minutes"<<d<<"seconds";
	return 0;
}

