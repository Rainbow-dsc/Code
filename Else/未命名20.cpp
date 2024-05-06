#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d=100,e;
	for(;d<=999;d++)
	{
		a=d%10;
		b=d/10%10;
		c=d/100%10;
		if(a*a*a+b*b*b+c*c*c==d)
		{
			cout<<d<<" ";
		}	
	}
	
	return 0;
}

