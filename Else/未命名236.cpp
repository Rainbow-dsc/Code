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
	for(int i=len-1;i>=0;i--)
	{
		cout<<a[i]; 
	}	
	return 0;
}


