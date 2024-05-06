#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[1000];
	int len=0;
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++)
	{ 
		if(a[i]>a[i-1])
		{
			int c=a[i];
			a[i]=a[i-1];
			a[i-1]=c;
		}
	} 
	cout<<a; 
	return 0;
}


