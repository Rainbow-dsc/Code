#include<iostream>
using namespace std;
int s=0;
int main()
{
	for(int i=1;i<=100;i++)
	{
		if(i%2!=0&&i%3!=0&&i%5!=0)
		{
			 s++; 
		}
	}
	cout<<s;
 	return 0;
}
