#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std; 
struct stu
{
	char m[4000];
	char b[100];
	char c[4000];
}
a[4040]; 
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].m>>a[i].b>>a[i].c;
	}
	char op[4000];
	cin>>op;
	for(int i=0;i<n;i++)
	{
		if(strcmp(op,a[i].b)==0)
		{
			cout<<a[i].m<<' '<<a[i].b<<' '<<a[i].c<<endl;
		}
	}
	return 0;
}


