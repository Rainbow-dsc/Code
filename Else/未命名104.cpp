#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[10000];
	char b[1000];
	gets(a);
	gets(b);
	int t=strlen(a);
	int u=strlen(b);
	if(a==b)
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
	return 0;
}

