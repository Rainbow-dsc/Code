#include<iostream>
using namespace std;
int main()
{
	for(int j=1;j<=9;j++)
	{
		for(int u=1;u<=j;u++)
		{
			if(u*j>=10)
			{
				cout<<j<<"*"<<u<<"="<<j*u<<" ";
			} 
			else
			{
				cout<<j<<"*"<<u<<"= "<<j*u<<" "; 
			}
		}
		cout<<endl;
	} 
	return 0;
}

