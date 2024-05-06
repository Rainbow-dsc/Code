#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main()
{
	char a[100],b;
	cin>>b>>a;
	int  len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]!=b)
		{
			cout<<a[i];
		}	
	}
	return 0;
}


