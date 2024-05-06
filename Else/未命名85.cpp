#include <iostream>
using namespace std;
int a,B,C,D,b;
int main()
{
	cin>>a;
	B=a/100;
	C=a%100/10;
	D=a%100%10;
	b=B+C+D;
	if(a%b==0)
	{
		cout<<2*a;	
	}
	else 
	{
		cout<<a;
	}
	return 0;
}
