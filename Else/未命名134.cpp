#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	char a[100];
	int u=0,m;
	m=strlen(a);
	cin>>a;
	for(int i=0;i<m;i++)
	{
		u=u*10+a[i]-'0';
	}
	cout<<u; 
	return 0;
}


