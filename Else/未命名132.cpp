#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100];
	int o;
	gets(a);
	o=strlen(a);
	for(int i=0;i<o;i++)
	{
		cout<<a[i];
	} 
	return 0;
}


