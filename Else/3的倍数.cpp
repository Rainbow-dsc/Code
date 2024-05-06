#include<iostream>
using namespace std;
int a,b,c,d,e,f;
int main()
{
	cin>>a;
	d=a%10;
	e=a/10%10;
	f=((d+e)%3)==0?a*3:a*2;
	cout<<f;
	return 0;
}

