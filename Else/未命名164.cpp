#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100];
	int k=1;
	gets(a);
	int u=strlen(a);
	for(int i=0;i<u;i++)
	{
		if(a[i]=='"'&&k==1)
		{
			a[i]='<';k=2;
		}
		else if(a[i]=='"'&&k==2)
		{
			a[i]='>';k=1;
		}
	}
	cout<<a;
	return 0;
}


