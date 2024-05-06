#include<iostream>
using namespace std;
int x,y,z;
int main()
{
	cin>>x>>y>>z;
	if((10*x+y)%7==0||(10*x+z)%7==0||(10*y+z)%7==0)
	{
		cout<<"1";	
	}
	else
	{
		cout<<"0";
	}
	return 0;
}

