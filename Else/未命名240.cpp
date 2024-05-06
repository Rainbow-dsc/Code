#include<iostream>
using namespace std;
int main()
{
	int  a;
	int b,sum=0; 
	cin>>a;
	while(a>0)
	{
		a=a/10;
		sum+=sum;
	}
	cout<<sum;
	return 0;
}
   
