#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[10];
	int SUM=0;
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		SUM=SUM*10+a[i]-48;
	}
	cout<<SUM;
	return 0;
}
