#include<iostream>
using namespace std;
int main()
{
	int a=102,b,c,d;
	b=a/100;
	c=a%100/10;
	d=a%10;
	if(b!=c!=d)
	{ 
		while(a<1000)
		{
		
		cout<<a<<' ';
		a=a+1;
		}
	} 
	return 0;
}


