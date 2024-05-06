#include<iostream>
using namespace std;
int main()
{
	int s=0,a=1;
	for(int i=1;i<=101;i=i+2)
	{
		s=s+i*a;
		a=a*-1;
	}
	cout<<s; 
	return 0;
}

