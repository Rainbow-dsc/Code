#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	int sum=0;
	char a[60];
	int b;
	cin>>a;
	b=strlen(a);
	for(int i=0;i<b;i++)
	{
		if(a[i]=='O')
		{
			int k=0;
			while(a[i]=='O')
			{
				k++;
				sum+=k;
				i++;
			}
		}
	} 
	cout<<sum;
	return 0;
}


