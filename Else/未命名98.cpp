#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
	char b[100];
	gets(b);
	int s=0;
	int len=strlen(b);
	for(int i=0;i<len;i++)
	{
		if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u')
		{
			s++; 
		}
	}
	cout<<s;
	return 0;
}

