#include<iostream>
using namespace std;
int main()
{
	int i[1000],m=0;
	for(int a=0;;a++)
	{
		cin>>i[a];
		m++;
		if(i[a]==0)
		{
			break;
		}
	}
	for(int a=m-1;a>=0;a--)
	{
		cout<<i[a]<<" ";
	}
	return 0;
}
