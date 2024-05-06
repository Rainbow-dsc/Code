#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100],b[100];
	cin>>a>>b;
	int len=strlen(a);
	int len1=strlen(b); 
	for(int i=0;i<len;i++)
	{
		if('A'<=a[i]&&a[i]<='Z')
		{
			a[i]=a[i]+32;
		}
	}
	for(int i=0;i<len1;i++)
	{
		if('A'<=b[i]&&b[i]<='Z')
		{
			b[i]=b[i]+32;
		}
	}
	if(strcmp(a,b)==0)
	{
	cout<<"YES";
	}  
	else
	{
	cout<<"NO";
	}
	return 0;
}


