#include<iostream>
#include<cstring>
#include<stdio.h> 
using namespace std;
int main()
{
	char a[100];
	int d,n=0;
	cin>>a;
	d=strlen(a);
	for(int i=0;i<d;i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
		{
			n=n+1;
		}
	}
	cout<<n;
	return 0;
}

