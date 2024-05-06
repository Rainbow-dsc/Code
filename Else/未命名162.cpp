#include<iostream>
using namespace std;
int s(int a,int b)
{
	int c;
	for(int i=1;i<=a&&i<=b;i++)
	{
		if(a%i==0&&b%i==0)
		{
			c=i;
		}
	} 
	return c;
}
int main()
{
	int a,b,c;
	cin>>a>>b;
	cout<<s(a,b);
	return 0;
}


