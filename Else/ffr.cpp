#include<iostream>
using namespace std;
int main()
{
	int a=1000,b,c,d,e,f=0;
	while(a<9999)
	{
		b=a/1000;
		c=a%1000/100;
		d=a%100/10;
		e=a%10;
		if(b!=d&&b==e&&c==d)
		{
			f=f+a; 
		}
		a=a+1;
	}
	cout<<f;
	return 0;
}

