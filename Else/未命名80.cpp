#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100],c,n;
	int b;
	gets(a); 
	b=strlen(a);
	for(int i=0;i<b;i++)
	{
		if('A'<=a[i]&&a[i]<='Z')
		{
			a[i]=a[i]+32;
		}
	}
	cout<<a;
	return 0;
}

