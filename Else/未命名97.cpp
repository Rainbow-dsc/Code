#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
	char a[100];
	char s;
	cin>>s;
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]!=s)
		{
			cout<<a[i];
		}
	}
	return 0;
}

