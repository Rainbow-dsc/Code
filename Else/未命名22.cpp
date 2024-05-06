#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d=1000,e;
	for(;d<=9999;d++)
	{
		a=d%10;
		b=d/10%10;
		c=d/100%10;
		e=d/1000%100;
		if(a*a*a*a+b*b*b*b+c*c*c*c+e*e*e*e==d)
		{
			cout<<d<<" ";
		}
	}
	return 0;
}

