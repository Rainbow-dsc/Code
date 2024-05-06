#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100];
	int c;
	gets(a);
	c=strlen(a);
	for(int i=c-1;i>=0;i--)
	{
		cout<<a[i];
	} 
	return 0;
}


