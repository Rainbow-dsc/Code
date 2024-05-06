#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int g,s,b,asn;
	g=a%10;
	s=a/10%10;
	b=a/100;
	a=b*100+s*10+g;
	asn=g*100+s*10+b;
	cout<<asn; 
	return 0;
}

