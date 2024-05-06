#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100];
	int b;
	gets(a);
	b=strlen(a);
	for(int i=0;i<b;i++)
	{
		cout<<a[i];
	}
	return 0;
}

