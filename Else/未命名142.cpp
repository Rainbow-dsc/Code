#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100]="0123456789abcdefghijklmnopqrstuvwxyz";
	char b[1000];
	gets(b);
	int c=strlen(b);
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(a[i]==b[j])
			{
				cout<<b[j];
			}
		}
	}
	
	return 0;
}


