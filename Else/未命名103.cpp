#include<iostream>
using namespace std;
int main()
{
	int W;
	cin>>W;
	if(W<=54)
	{
		cout<<1; 
	} 
	else if(54<W&&W<=59) 
	{
		cout<<2;
	}
	else if(59<W&&W<=64)
	{
		cout<<3; 
	}
	else if(64<W&&W<=76)
	{
		cout<<4;
	}
	else if(76<W&&W<=83)
	{
		cout<<5;
	}
	else if(83<W&&W<=91)
	{
		cout<<6;
	}
	else if(91<W&&W<=130)
	{
		cout<<7;
	}
	return 0;
}

