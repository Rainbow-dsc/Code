#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main()
{
	char a[100];
	gets(a);
	int  len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(65<=a[i]&&a[i]<=90)
		{
			a[i]=a[i]+32;
			
		}
		cout<<a[i];
	}	
	
	return 0;
}


