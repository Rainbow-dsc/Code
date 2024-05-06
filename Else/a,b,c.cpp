#include<iostream>
using namespace std;
int a,b,c,temp1,temp2;
int main()
{
	cin>>a>>b>>c;
	temp1=c;
	c=a;
	temp2=b;
	b=temp1;
	a=temp2;
	cout<<"a="<<a<<" "<<"b="<<b<<" "<<"c="<<c; 
	return 0;
}

